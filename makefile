# Definitions
CC := gcc
CFLAGS := -g -Wall
EXE_EXT :=
RM := rm -f
LIBS :=
RUN := ./
SRC_DIR := src
BUILD_DIR := build

# Determine if OS is Windows
ifeq ($(OS),Windows_NT)
    RM := del /Q /F
    EXE_EXT := .exe
    LIBS := -lws2_32
    RUN := 
endif

# Targets
EXE := $(BUILD_DIR)/webserver$(EXE_EXT)
OBJS := $(BUILD_DIR)/webserver.o

# Rules
.PHONY: all
all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)    # Windows system
	@if exist "$(BUILD_DIR)\*.exe" for %%X in ($(BUILD_DIR)\*.exe) do $(RM) "%%X"
	@if exist "$(BUILD_DIR)\*.o" for %%X in ($(BUILD_DIR)\*.o) do $(RM) "%%X"
else                        # Unix-like system
	-$(RM) $(BUILD_DIR)/*$(EXE_EXT) $(BUILD_DIR)/*.o
endif

.PHONY: run
run: $(EXE)
	$(RUN)$(EXE)