#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //For socket
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080

int main(void) {


    int socket_fd, new_socket; //Socket descriptor
    //int opt = 0;
    //int setsockopt; //Used for mainpulating options for the socket
    //int opt = 1;
    struct sockaddr_in address; //Socket address
    int addlen = sizeof(address);
    char *buffer = malloc(1024);
    //char* testMessage = "Test";

    //Create socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failure to create socket.");
        exit(EXIT_FAILURE);
    }

    /*
    //Setsockopt, i
    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failure in using setsockopt.");
        exit(EXIT_FAILURE);
    }
    */

    //Specify the address for binding
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    //Bind the socket to specific port
    if(bind(socket_fd, (struct sockaddr *) &address, sizeof(address)) < 0){
        perror("Failure to bind socket.");
        exit(EXIT_FAILURE);
    }

    //Listen (socketfd, backlog)
    printf("Listening to port %d...\n", PORT);

    if(listen(socket_fd, 3) == -1) {
        perror("Error listening to port");
        exit(EXIT_FAILURE);
    }

    //Accept accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    if((new_socket = accept(socket_fd, (struct sockaddr *) &address, (socklen_t *)&addlen)) == -1) {
        perror("Failure in accepting connection.");
        exit(EXIT_FAILURE);
    }

  

    //Read from buffer until end of file
    while(read(new_socket, buffer, 1024) != 0) {
        printf("%s\n", buffer);
        
        //Clear buffer after printing message
        memset(buffer, 0, 1024);
    }
    printf("Message received: ");
    //send(socket_fd, testMessage, strlen(testMessage) , 0 );
    //printf("Hello message sent\n");
    

    free(buffer);
    return 0;
}
