#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //For socket
#include <netinet/in.h>

#define PORT 8080

int main(void) {


    int socket_fd;
    //Create socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failure to create socket.");
        exit(EXIT_FAILURE);
    }

    //Bind

    //Listen

    //Accept

    return 0;
}
