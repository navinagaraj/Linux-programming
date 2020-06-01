/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 28-05-2020                  */
/* Filename     : process1.c                  */
/* Description  : creating a posix semaphores */
/**********************************************/

 #include "my_header.h"

int main(){
	sem_t my_sem;
	int open_fd, shm_open_fd, sem_init_ret, msyns_ret;
	ssize_t ret_read;
	char buffer[18];
	 char *mmap_ret;
	sem_init_ret =  sem_init(&my_sem, 1, 2);

	sem_wait(&my_sem);
	shm_open_fd = shm_open("/data",O_CREAT|O_RDWR,0600);
	perror("shm_open");
	mmap_ret = mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,shm_open_fd,0);
	perror("mmap ");
	msyns_ret = msync(mmap_ret,20,MS_SYNC);
	perror("msync");


	ret_read = read(shm_open_fd,buffer,18);

	printf("%s",buffer);

	sem_post(&my_sem);

}
