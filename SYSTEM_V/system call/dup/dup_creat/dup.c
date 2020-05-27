#include "dup.h"

int main(){
	char buffer[121],buffer_1[121],w_buffer[62]="This is a normal fd data This is not a normal fd is a dup 1 ",w_buffer_2[61]="This 2 is a normal fd data This is not a normal fd is a dup\n";
	int open_fd,dup_fd,a,b,retur,data;
	ssize_t read_fd,write_fd,close_fd,fd;

	open_fd = open("./sample.txt", O_RDWR|O_APPEND);//open and possibly create a file//
	perror("open");
	dup_fd  = dup(open_fd);// duplicate a file descriptor//
	perror("dup");

	write_fd = write(open_fd, w_buffer, strlen(w_buffer));
	printf("%ld\n",write_fd);
	write_fd = write(dup_fd, w_buffer_2, strlen(w_buffer_2));
	printf("%d\n",b = write_fd);

	lseek(open_fd, 0,SEEK_SET);//reposition read/write file offset//

	read_fd = read(open_fd, buffer, 5);
	//perror("read");
	printf("%ld\n",read_fd);
	printf("buffer   = %s\n",buffer);

	read_fd =read(dup_fd, buffer_1,5);
       //perror("read");
	printf("%ld\n",read_fd);
	printf("buffer_1 = %s\n",buffer_1);

	close_fd = close(open_fd);
	close_fd = close(dup_fd);
}
