#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h> //For socket
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h> //For threads

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *clientHandler();

int main(void) {

    /*
    pthread_t thread_id[MAX_CLIENTS];

    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(pthread_create(&thread_id[i], NULL, connectClient, NULL) != 0) {
            //pthread_create doesn't change errno (?)
            printf("Error creating thread!\n");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(thread_id[i], NULL);
    }
    */
    
    int serverSocket, new_socket; //Socket descriptor
    //int opt = 0;
    //int setsockopt; //Used for mainpulating options for the socket
    //int opt = 1;
    struct sockaddr_in address; //Socket address
    int addlen = sizeof(address);
    char *buffer = malloc(1024);


    //Create socket
    if((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failure to create socket.");
        exit(EXIT_FAILURE);
    }

    /*
    //Setsockopt, i
    if(setsockopt(serverSocket, SOL_SOCKET, SO_REUSADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failure in using setsockopt.");
        exit(EXIT_FAILURE);
    }
    */

    //Specify the address for binding
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    
    //Bind the socket to specific port
    if(bind(serverSocket, (struct sockaddr *) &address, sizeof(address)) < 0){
        perror("Failure to bind socket.");
        exit(EXIT_FAILURE);
    }

    //Listen (socketfd, backlog)
    printf("Listening to port %d...\n", PORT);

    if(listen(serverSocket, 5) == -1) {
        perror("Error listening to port");
        exit(EXIT_FAILURE);
    }

    //Accept connection from up to max amount of clients, do while ?
    
    if((new_socket = accept(serverSocket, (struct sockaddr *) &address, (socklen_t *)&addlen)) == -1) {
        perror("Failure in accepting connection.");
        exit(EXIT_FAILURE);
    }


    //Read from buffer until end of file
    while(read(new_socket, buffer, 1024) != 0) {

        printf("%s\n", buffer);
        
        //Clear buffer after printing message
        memset(buffer, 0, 1024);
    }


    
    //send(serverSocket, testMessage, strlen(testMessage) , 0 );
    //printf("Hello message sent\n");
    

    free(buffer);


    return 0;
}

void *clientHandler() {
    
   
    return NULL;
}