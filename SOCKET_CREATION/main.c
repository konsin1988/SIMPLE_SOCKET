#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char** argv)
{
	int socket_desc;
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	/* AF_INET - IP version 4; SOCK_STREAM - connection oriented 
	 * TCP protocol; Protocol - 0 or IPPROTO_IP, this is IP protocol */
	if (socket_desc == -1)
	{
		printf("Could not create socket\n");
	}
	return 0;
}
