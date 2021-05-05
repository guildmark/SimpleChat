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
#define MAX_USER 30
#define MAX_BUFFER 1024

/*
const char *getUser() {

	char *user = malloc(MAX_USER);

	printf("Enter username (max 30 characters): ");
	scanf("%s", user);

	printf("Welcome to SimpleChat [%s]!\n", user);
	
	return user;
}
*/

void connectToServer(char *buffer, char *user, struct sockaddr_in servAddress) {

	//Get username


	int clientSocket = 0;
	int addlen = sizeof(servAddress);
	
	printf("Enter username (max 30 characters): ");
	scanf("%s", user);

	printf("Welcome to SimpleChat [%s]!\n", user);

	//create the socket
	if((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Failure to create socket");
		exit(EXIT_FAILURE);
	}

	servAddress.sin_family = AF_INET;
	servAddress.sin_port = htons(PORT);
	servAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	//Convert IP to binary
	if(inet_pton(AF_INET, "127.0.0.1", &servAddress.sin_addr)<=0) {
		perror("Invalid address");
		exit(EXIT_FAILURE);
	}

	printf("Connecting to server on port %d..\n", PORT);
	//Connect to server int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	if(connect(clientSocket, (struct sockaddr *)&servAddress, addlen) < 0) {
		perror("Error connecting to server");
		exit(EXIT_FAILURE);
	}

	printf("Connected to server.\n");

	//Get the input from user
	while(fgets(buffer, 1024, stdin) != NULL) {
		send(clientSocket, buffer, strlen(buffer), 0);
		//printf("Sending message: %s..\n", testMessage);

		//Check if the client will exit the server (dont need cus fgets checks for NULL?)
	
	}

	//free(user);

}

int main(void) {

	struct sockaddr_in servAddress;
	char buffer[MAX_BUFFER];
	char user[MAX_USER];
	
	//connect to server
	connectToServer(buffer, user, servAddress);



	return 0;
}
