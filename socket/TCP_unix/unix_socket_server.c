/*********************************************/
/* Author	: Navin kumar .N             */
/* Date		: 28-2-2019                  */
/* Filename	: TCP_unix_socket_server.c   */
/* Description	: socket sample program      */
/*********************************************/


#include "unix_socket_server.h"
int main()
{
	int socket_fd1,socket_fd2;
	struct sockaddr_un unix_addr;
	char str1[200];

	unix_addr.sun_family = AF_UNIX;

	/*  strcpy, strncpy - copy a string */
	strcpy(unix_addr.sun_path,"./socket1");

	/*opening s UNIX socket,with SOCK_STREAM type protocol*/
	socket_fd1 = socket(AF_UNIX,SOCK_STREAM,0);


	/*binding with 'socket1' socket file*/
	bind(socket_fd1, (struct sockaddr*)&unix_addr,sizeof(unix_addr));


 	/*listen - listen for connections on a socket*/
	listen(socket_fd1,5);

	/* accept, accept4 - accept a connection on a socket */
	socket_fd2=accept(socket_fd1,NULL,NULL);

	/* read - read from a file descriptor */
	read(socket_fd2,str1,50);

	/* printing the string */
	printf("%s\n",str1);

	//socket will be closed
	close(socket_fd1);
}
