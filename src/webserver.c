
#if defined(__unix__)
#define OS_UNIX
#elif defined(__linux__)
#define OS_LINUX
#elif defined(__APPLE__)
#define OS_APPLE
#elif defined(__FreeBSD__)
#define OS_FREEBSD
#elif defined(_WIN32)
#define OS_WINDOWS
#endif


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifdef OS_WINDOWS
    #include <winsock2.h>
#elif defined(OS_LINUX)
    #include <sys/socket.h>
    #include <netinet/in.h>
#endif

#ifdef OS_WINDOWS
    #define EXIT(x) return x;
#elif defined(OS_LINUX)
    #define EXIT(x) exit(x);
#endif

int main(){

    #ifdef OS_WINDOWS
        WSADATA wsaData;
        int err = WSAStartup(MAKEWORD(2,2), &wsaData);
        if(err != 0) {
            fprintf(stderr, "WSAStartup failed with error: %d\n", err);
            EXIT(1);
        }
    #endif

    //Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0){
        perror("socket");
        EXIT(1);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) <0) {
        perror("bind");
        EXIT(1);
    }

    //Listen for connection
    listen(socket_fd, 5);

    //Accept connection requests
    while(1) {

        #ifdef OS_WINDOWS
            SOCKET client_fd = accept(socket_fd, NULL, NULL);
        #elif defined(OS_LINUX)
            int client_fd = accept(socket_fd, NULL, NULL);
        #endif

        if(client_fd < 0) {
            perror("accept");
            EXIT(1);
        }

        //read request from the client
        char request[1024];
        int bytes_read;

        #ifdef OS_WINDOWS
            bytes_read = recv(client_fd, request, sizeof(request), 0);
        #else
            bytes_read = read(client_fd, request, sizeof(request));
        #endif

        if(bytes_read < 0) {
            perror("read");
            EXIT(1);
        } 

        //Respond to the request
        const char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>";
        
        #ifdef OS_WINDOWS
            int bytes_send = send(client_fd, response, sizeof(response), 0);
            if(bytes_send == SOCKET_ERROR) {
                perror("send");
                EXIT(1);
            }
        #else
            write(client_fd, response, sizeof(response));
        #endif

        //Close the application
        close(client_fd);
    }

    #ifdef OS_WINDOWS
        WSACleanup();
    #endif

    return 0;
}


