/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 19-05-2020                  */
/* Filename     : process2.c                  */
/* Description  : creat a POSIX shared memoey */
/**********************************************/
#include "posix_sm.h"



int main(){
	
	char buffer[MAXSIZE];
	int shm_open_fd, msync_fd, munmap_ret;
	ssize_t read_fd;
	char *ptr;

	shm_open_fd =  shm_open("/my_data_",  O_RDWR, 0644);
	if(shm_open_fd == -1){
		perror("shm_open");
		return 0;
	}else{
		perror("shm_open");
	}
	read_fd = read(shm_open_fd, buffer, MAXSIZE);
	perror("read");

	ptr = mmap( NULL, MAXSIZE, PROT_READ|PROT_WRITE, MAP_SHARED, shm_open_fd, 0);
	perror("mmap");

	msync_fd =  msync( ptr, MAXSIZE,  MS_SYNC);
	if(msync_fd == -1){
		perror("msync");
		return 0;
	}else{
		perror("msync");
	}
	printf("%s",buffer);
	munmap_ret = munmap(ptr, MAXSIZE);
	perror("munmap");
}
