/******************************************/
/* Author	: Navin kumar .N          */
/* Date		: 23-2-2019               */
/* Filename	: internet_ipv4_server.c  */
/* Description	: IPV4 socket             */
/******************************************/

/* Included header file */

#include "internet_ipv4_server.h"

/* Global variable definitions */
	socklen_t length = sizeof(struct sockaddr_in);
	unsigned int ip_v4;
	unsigned char str1[500],str2[500];
	struct sockaddr_in socketaddr;
	int worker,p_1,p_2;
	void *love_fun_1();
	void *love_fun_2();
/* function definitions */
 
int main(int argc, char *argv[])
{

	pthread_t love_thread_1,love_thread_2;

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
	while(1)
	{
	/* pthread_create - create a new thread  ::REFERENC IN " man pthread_create "*/
	p_1=pthread_create(&love_thread_1,NULL,love_fun_2,NULL);
	/* pthread_create - create a new thread  ::REFERENC IN " man pthread_create "*/
	p_2=pthread_create(&love_thread_2,NULL,love_fun_1,NULL);
	}
	
}
		
void *love_fun_1()
	{
	/* recv, recvfrom, recvmsg - receive a message from a socket :: REFERENC IN "  man recvfrom "*/	
	recvfrom(worker, str1,100, 0,(struct sockaddr *)&socketaddr, &length);
	printf("%s\n",str1);
	}

void *love_fun_2()
	{
	scanf("%[^\n]%*c",str2);
	/* send, sendto, sendmsg - send a message on a socket :: REFERENC IN " man sendto "*/
	sendto(worker, str2,strlen(str2)+1, 0,(struct sockaddr *)&socketaddr, sizeof(socketaddr));
	} 
