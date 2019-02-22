/*****************************************/
/* Author	: Navin kumar .N         */
/* Date		: 22-2-2019              */
/* Filename	: unix_socket_client.c   */
/* Description	: socket sample program  */
/*****************************************/


#include "unix_socket_client"

int main()
{
	char str1[]="message from client\n";
	int socket_fd1;
	struct sockaddr_un unix_addr;

	unix_addr.sun_family = AF_UNIX;
	strcpy(unix_addr.sun_path,"./socket1");

	//opening a UNIX socket, with DGRAM type protocol
	socket_fd1 = socket(AF_UNIX,SOCK_DGRAM,0);

	//sending first message
	sendto(socket_fd1, str1, strlen(str1)+1, 0, (struct sockaddr*)&unix_addr,sizeof(unix_addr));

	//socket will be closed
	close(socket_fd1);
}
