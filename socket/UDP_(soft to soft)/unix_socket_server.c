/*****************************************/
/* Author	: Navin kumar .N         */
/* Date		: 22-2-2019              */
/* Filename	: unix_socket_server.c   */
/* Description	: socket sample program  */
/*****************************************/


#include "unix_socket_server"
int main()
{
	int socket_fd1;
	struct sockaddr_un unix_addr;
	socklen_t length;
	char str1[200];

	unix_addr.sun_family = AF_UNIX;
	strcpy(unix_addr.sun_path,"./socket1");

	//opening s UNIX socket,with DGRAM type protocol
	socket_fd1 = socket(AF_UNIX,SOCK_DGRAM,0);

	//binding with 'socket1' socket file
	bind(socket_fd1, (struct sockaddr*)&unix_addr,sizeof(unix_addr));

	//sending first message
	recvfrom(socket_fd1, str1, 100, 0,(struct sockaddr *)&unix_addr, &length);

	printf("%s\n",str1);

	//socket will be closed
	close(socket_fd1);
}
