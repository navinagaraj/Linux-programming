/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 23-05-2020                  */
/* Filename     : mlock_munlock.c             */
/* Description  : protect a maped file        */
/**********************************************/

#include "mlock_munlock.h"


int main(){
	int mprotect_fd, open_fd, mlock_ret, msync_ret, munlock_ret;
	ssize_t write_fd;
	char *ptr;
	char buffer_2[]="Hi data in shared memory\n";



	open_fd = open( "./my_shared_data", O_CREAT|O_RDWR,  S_IRWXU|S_IRGRP|S_IROTH);
	if(open_fd == -1){
		perror("open");
	}
	else{
		perror("open");
	}
	write_fd =  write( open_fd, buffer_2, sizeof(buffer_2));
	if(write_fd != sizeof(buffer_2)){
		printf("Error in write\n");
	}else{
		printf("sucess in write\n");
	}

	 ptr = mmap( NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, open_fd, 0);
	 if(ptr == MAP_FAILED)
		 perror("mmap");
	 else
		 perror("mmap");
	msync_ret =  msync(ptr , 4096 , MS_SYNC );
	perror("msync");
	mlock_ret =  mlock(ptr, 4096);
	if(mlock_ret == -1){
		perror("mlock");
	}
	else{
		perror("mlock");
	}
	munlock_ret =  munlock(ptr, 4096);
	if(munlock_ret == -1){
		perror("munlock");
	}
	else{
		perror("munlock");
	}

}
