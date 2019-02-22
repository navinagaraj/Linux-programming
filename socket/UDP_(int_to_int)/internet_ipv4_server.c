/******************************************/
/* Author	: Navin kumar .N          */
/* Date		: 22-2-2019               */
/* Filename	: internet_ipv4_server.c  */
/* Description	: IPV4 socket             */
/******************************************/

/* Included header file */

#include "internet_ipv4_server.h"

/* Global variable definitions */


/* function definitions */
 
int main(int argc, char *argv[])
{
	int worker;
	struct sockaddr_in socketaddr;
	unsigned char str1[200];
	unsigned int ip_v4;

	socklen_t length = sizeof(struct sockaddr_in);

	/* socket - create an endpoint for communication :: REFERENC IN  " man socket " */
	worker=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");

	/* memset - fill memory with a constant byte :: REFERENC IN " man memset " */
	memset(&socketaddr, 0, sizeof(struct sockaddr_in));

	socketaddr.sin_family =AF_INET;
	socketaddr.sin_port  = htons(atoi(argv[1]));

	/* inet_pton  -  convert  IPv4  and IPv6 addresses from text to binary form :: REFERENCE IN " man inet_pton " */
	ip_v4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);

	/*bind - bind a name to a socket :: REFERENC IN " man bind "  */
	bind(worker,(struct sockaddr *)&socketaddr,sizeof(socketaddr));
	perror("bind");

	/* recv, recvfrom, recvmsg - receive a message from a socket ::REFERENC IN " man recvfrom " */
	recvfrom(worker, str1,100, 0,(struct sockaddr *)&socketaddr, &length);

	printf("%s\n",str1);
	close(worker);
} 
