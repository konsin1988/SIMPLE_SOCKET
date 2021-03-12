#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int hostname_to_ip(char* hostname, char* ip)
{
	struct hostent *he;
	struct in_addr **addr_list;
	int i;

	if ( (he = gethostbyname( hostname ) ) == NULL)
	{
		herror("gethostbyname");
		return 0;
	}

	addr_list = (struct in_addr**)he->h_addr_list;

	for(i=0; addr_list[i] != NULL; ++i)
	{
		strcpy(ip, inet_ntoa(*addr_list[i]) );
	}

	return 1;
}
