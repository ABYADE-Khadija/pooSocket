#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT1 4455
#define PORT2 4456

void main(){

	int sockfd;
	struct sockaddr_in server_addr;

	int new_socket;
	struct sockaddr_in new_addr;

	socklen_t taille_addr;
	char message[1024];
        int clientSocket; 

	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	memset(&server_addr, '\0', sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT1);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

	listen(sockfd, 5);

        taille_addr=sizeof(new_addr);

	new_socket = accept(sockfd, (struct sockaddr*)&new_addr, &taille_addr);
	recv(new_socket, message, 1024, 0);
        printf("%s\n",message);
        strcpy(strcat(message,"wssl a saat "),message);


	clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT2);
	server_addr.sin_addr.s_addr= inet_addr("127.0.0.2");

	connect(clientSocket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	send(clientSocket , message, 100, 0);








}
