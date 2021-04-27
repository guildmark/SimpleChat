/*A program that acts as a simple chat, where the goal is for two terminal
windows to chat with each other */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //For socket
#include <netinet/in.h>

#define HOSTNAME "guildmark"
#define PORT 8080

int main(void) {

	
	int server_fd;
	//struct sockaddr_in address;

	//dsdseate the socket
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("Failure to create socket.");
		exit(EXIT_FAILURE);
	}
			
	
	printf("Created server with fd: %d\n", server_fd);



	return 0;
}
