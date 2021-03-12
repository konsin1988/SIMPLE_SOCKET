#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "hostname_to_ip.h"

int main(int argc, char** argv)
{
	char* hostname = "www.google.com";
	char* ip = (char*)malloc(100*sizeof(char)); 
	int socket_desc;
	struct sockaddr_in server;
	char* message, server_reply[2000];

	/*** Create socket ***/
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1 )
	{
		printf("Could not create socket");
	}
	hostname_to_ip(hostname, ip);
	server.sin_addr.s_addr = inet_addr(ip);
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	/*** connect to remote server ***/
	if (connect(socket_desc, (struct sockaddr *)&server, 
				sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected\n");

	/*** Send some data ***/
	message = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
	if (send(socket_desc, message, strlen(message), 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

	/*** Receive a reply from the server ***/
	if (recv(socket_desc, server_reply, 2000, 0) < 0)
	{
		puts("recv failed");
	}
	puts("reply received\n");
	puts(server_reply);

	close(socket_desc);

	return 0;
}
