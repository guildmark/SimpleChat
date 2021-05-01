/*A client program that acts as a simple chat, where the goal is for two terminal
windows to chat with each other with the possibility of using two different computers*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> //For socket
#include <netinet/in.h>
#include <arpa/inet.h>

#define HOSTNAME "guildmark"
#define PORT 8080

int main(int argc, const char *argv[]) {

	
	int socket_fd = 0, valread;
	struct sockaddr_in address;
	int addlen = sizeof(address);
	char buffer[1024];
	char* testMessage = "Test";

	//create the socket
	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Failure to create socket");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	
	//Convert IP to binary
	if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0) {
		perror("Invalid address");
		exit(EXIT_FAILURE);
	}

	printf("Connecting to server on port %d..\n", PORT);
	//Connect to server int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if(connect(socket_fd, (struct sockaddr *)&address, addlen) < 0) {
		perror("Error connecting to server");
		exit(EXIT_FAILURE);
	}

	printf("Connected to server.\n");

	//Get the input from user
	while(fgets(buffer, 1024, stdin) != NULL) {
		send(socket_fd, buffer, strlen(buffer), 0);
		//printf("Sending message: %s..\n", testMessage);
	}

	//Send message to server


	return 0;
}
