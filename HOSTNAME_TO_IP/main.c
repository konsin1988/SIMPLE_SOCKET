#include <stdio.h>
#include <stdlib.h>

#include "hostname_to_ip.h"

int main(int argc, char** argv)
{
	char* hostname = "www.google.com";
	char* ip = (char*)malloc(100*sizeof(char));
	if( !hostname_to_ip(hostname, ip))
	{
		printf("transformation failed");
	}
	printf("%s resolved to : %s\n", hostname, ip);

	return 0;
}
