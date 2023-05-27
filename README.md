# Web Server Project

This is a simple web server project written in C.

## Prerequisites

Before you can build and run this project, you need to have `gcc` (the GNU Compiler Collection) and `make` installed on your system.

### Installation on Ubuntu

Run the following command to install `gcc` and `make`:

```bash
sudo apt update
sudo apt install build-essential
```

### Installation on Windows

For Windows, you can install `gcc` and `make` by following these steps:

1. Download the installer for [MinGW](http://www.mingw.org/) (Minimalist GNU for Windows).
2. Run the installer and choose your desired installation options.
3. During the installation process, select the components `mingw32-base` and `mingw32-gcc-g++`.
4. Choose an installation directory (e.g., `C:\MinGW`), and remember this location as you will need it to add MinGW to your PATH.
5. Once the installation is complete, you need to add MinGW to your PATH:
   - Open the Start menu and search for "Environment Variables."
   - Click on "Edit the system environment variables."
   - In the System Properties window, click on the "Environment Variables" button.
   - In the "System Variables" section, find the `Path` variable and select it.
   - Click on the "Edit" button.
   - Click on the "New" button and enter the path to your MinGW `bin` directory (e.g., `C:\MinGW\bin`).
   - Click "OK" to save the changes.
   - Close any open command prompt windows and reopen them for the changes to take effect.

## Building and Running the Project
To build and run this project, follow these steps:

1. Open a terminal or command prompt.

2. Navigate to the project's root directory.

3. Run the following **'make'** commands:

- **'make all'** or simply **'make'**: Builds the project.
- **'make run'**: Runs the executable file created by **'make all'**.
- **'make clean'**: Deletes the executable and all intermediate files.
For example, to build and run the project, you can use:
```
make
make run
```

And to clean up when you're done, use:
```
make clean
```

Make sure to execute these commands in the project's root directory, where the Makefile is located.

4. After running the web server, you can access it in a web browser by navigating to either **'localhost:8080'** or **'127.0.0.1:8080'**. These addresses refer to the local machine and the port number 8080, which is the default port for the web server.

For example, enter **'http://localhost:8080'** or **'http://127.0.0.1:8080'** in your web browser's address bar.

You should see the response from the web server displayed in the browser.