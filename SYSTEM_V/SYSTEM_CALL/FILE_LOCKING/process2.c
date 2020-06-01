/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 29-05-2020                  */
/* Filename     : process1.c                  */
/* Description  : File locking                */
/**********************************************/


#include "my_header.h"

int main(){
	
	int open_fd, flock_ret,a;
	ssize_t ret_write;
	struct flock my_lock;
	char buffer[]="My data in this file\n";



//	my_lock.l_type   = F_WRLCK;	
//	my_lock.l_whence = SEEK_SET;
//	my_lock.l_start  = 0;
//	my_lock.l_len    = 20;
	my_lock.l_pid    = getpid();

	open_fd =  open("./my_data.txt",O_RDWR);
	perror("open");

	if(fcntl( open_fd, F_SETLK,&my_lock) == -1){
		printf("Error in fcntl or another process using it\n");
		return 0;
	}else{
	perror("fcntl");
	flock(open_fd, LOCK_EX);
	perror("flock");
	printf("File is locked\n");
	}


	for(int a = 0; a < 20; a++){
		printf("PID = %d Writing in the file...\n",getpid());
		sleep(1);
	}

	ret_write = write(open_fd, buffer, sizeof(buffer));
	perror("write");

	flock(open_fd, LOCK_UN);
	perror("flock");

	close(open_fd);
	perror("close");
}
