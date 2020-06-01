/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 28-05-2020                  */
/* Filename     : process1.c                  */
/* Description  : creating a posix semaphores */
/**********************************************/

 #include "my_header.h"

int main(){
	sem_t my_sem;
	int open_fd ,ret_write, sem_init_ret;
	ssize_t ret_read;
	char buffer[20]={"Data from process1"};
	int shm_open_fd, msyns_ret, munmap_ret;
	char *mmap_ret;


	sem_init_ret =  sem_init(&my_sem, 1, 2);
	perror("sem_init");

	sem_wait(&my_sem);

	shm_open_fd = shm_open("/data",O_CREAT|O_RDWR,0600);
	perror("shm_open");
	ret_write = write(shm_open_fd,buffer,18);

	mmap_ret = mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,shm_open_fd,0);
	perror("mmap ");
	msyns_ret = msync(mmap_ret,20,MS_SYNC);


	for(int i = 0; i<20; i++){
		printf("Process1 writing...\n");
		sleep(1);
	}
	printf("Write data = %s\n",buffer);


	sem_post(&my_sem);


	munmap_ret = munmap(mmap_ret,20);
}
