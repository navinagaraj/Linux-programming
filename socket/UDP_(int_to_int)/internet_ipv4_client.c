/*******************************************/
/* Author	: Navin kumar .N           */
/* Date		: 22-2-2019                */
/* Filename	: internet_ipv4_client.c   */
/* Description	: socket                   */
/*******************************************/

/* Included header file */

#include "internet_ipv4_client.h"

/* Global variable definitions */


/* function definitions */
 
int main(int argc,char *argv[])
{
	int worker;
	unsigned int ip_v4;
	struct sockaddr_in socketaddr;

	/* write some message in string */
	unsigned char str1[]="IPV4 SOCKET FROM CLIENT";

	unsigned char ip_addr[] = "192.168.1.11";

	socklen_t length = sizeof(struct sockaddr_in);

	/* socket - create an endpoint for communication : REFERENC IN  " man socket " */
	worker=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");

	/* memset - fill memory with a constant byte :REFERENC IN " man memset " */
	memset(&socketaddr, 0, sizeof(struct sockaddr_in));
	socketaddr.sin_family =AF_INET;

	/* htonl,  htons,  ntohl, ntohs - convert values between host and net‐work byte order:REFERENC IN " man htons " */
	/* atoi, atol, atoll - convert a string to an intege : REFERENC IN " man atoi "*/
	socketaddr.sin_port  = htons(atoi(argv[1]));

	/* inet_pton  -  convert  IPv4  and IPv6 addresses from text to binary form :REFERENCE IN " man inet_pton " */
	ip_v4 = inet_pton(AF_INET,argv[2],&socketaddr.sin_addr);

	/* send, sendto, sendmsg - send a message on a socket :REFERENC IN " man sendto "*/
	sendto(worker, str1,strlen(str1)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));
	perror("sendto");

	sleep(2);

	close(worker);
}
