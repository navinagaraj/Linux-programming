/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 21-05-2020                  */
/* Filename     : process1.c                  */
/* Description  : creat a POSIX shared memoey */
/**********************************************/
#include "posix_sm.h"



int main(){
	
	char buffer[MAXSIZE]="Message from process1 POSIX working\n";
	int shm_open_fd,msync_fd,ret_write,munmap_ret;
	char *ptr;

	shm_open_fd =  shm_open("/my_data_", O_CREAT|O_RDWR, 0644);
	if(shm_open_fd == -1){
		perror("shm_open");
		return 0;
	}else{
		perror("shm_open");
	}
	ret_write = write(shm_open_fd,buffer,MAXSIZE);
	perror("write");

	ptr = mmap( NULL, MAXSIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE, shm_open_fd, 0);
	perror("mmap");

	msync_fd =  msync( ptr, MAXSIZE,  MS_SYNC);
	if(msync_fd == -1){
		perror("msync");
		return 0;
	}else{
		perror("msync");
	}
	munmap_ret = munmap(ptr, MAXSIZE);
	perror("munmap");
}
