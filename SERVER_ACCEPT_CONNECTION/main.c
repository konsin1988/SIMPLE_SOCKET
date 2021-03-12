#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv)
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char* message;

	/*** Create socket ***/
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
		goto failure;
	}

	/*** Prepare the sockaddr_in structure ***/
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );

	/*** Bind ***/
	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("bind failed");
		goto failure;
	}
	puts("bind done");

	/*** Listen ***/
	listen(socket_desc, 3);

	/*** Accept and incoming connection ***/
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while( new_socket = accept(socket_desc, (struct sockaddr*)&client, 
			(socklen_t*)&c))
	{
		puts("Connection accepted");
		
		/*** Reply to the client ***/
		message = "Hello, Client! I have receive your connection!\n";
		write(new_socket, message, strlen(message));

	}
	if (new_socket < 0)
	{
		perror("accept failed");
		goto failure;
	}


	/*** Client ip and the port of connection ***/
	char* client_ip = inet_ntoa(client.sin_addr);
	int client_port = ntohs(client.sin_port);
	printf("\nClient IP is %s\nClient port is %d\n", 
			client_ip, client_port);


failure:	
	close(socket_desc);
	close(new_socket);
	return 0;
}
