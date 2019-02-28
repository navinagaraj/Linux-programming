/*********************************************/
/* Author	: Navin kumar .N             */
/* Date		: 28-2-2019                  */
/* Filename	: TCP_unix_socket_client.c   */
/* Description	: socket sample program      */
/*********************************************/


#include "unix_socket_client.h"

int main()
{
	char str1[]="message from client\n";

	int socket_fd1;
	struct sockaddr_un unix_addr;

	unix_addr.sun_family = AF_UNIX;

	/*  strcpy, strncpy - copy a string */
	strcpy(unix_addr.sun_path,"./socket1");

	/* opening a UNIX socket, with SOCKET_STREAM type protocol */
	socket_fd1 = socket(AF_UNIX,SOCK_STREAM,0);

	/* connect - initiate a connection on a socket */
	connect(socket_fd1,(struct sockaddr *)&unix_addr,sizeof(unix_addr));

	/*  write - write to a file descriptor */
	write(socket_fd1,str1,50);

	//socket will be closed
	close(socket_fd1);
}
