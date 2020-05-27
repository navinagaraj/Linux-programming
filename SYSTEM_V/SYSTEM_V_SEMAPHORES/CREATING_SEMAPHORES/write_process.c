/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 25-05-2020                  */
/* Filename     : write_process.c             */
/* Description  : creating semaphores         */
/**********************************************/


#include "my_header.h"


int main(){
	int semget_fd, semctl_ret, semop_ret, open_fd, close_ret;
	ssize_t ret_write;
	char buffer_1[]="my data from write_process\n";

	struct sembuf my_sembuf;

	my_sembuf.sem_num =  3;
	my_sembuf.sem_op  = -3;

	semget_fd =  semget(18, 5, IPC_CREAT|0644);
	perror("semget");
	semop_ret =  semop(semget_fd, &my_sembuf, 1);
	perror("semop");

	printf("PID = %d is started to reading\n",getpid());


	open_fd =  open("./my_data.txt", O_RDWR);
	perror("open");
	ret_write = write( open_fd, buffer_1, sizeof(buffer_1));
	perror("write");

	close_ret =  close(open_fd);
	perror("close");

	printf("PID = %d is complited  reading\n",getpid());

	my_sembuf.sem_op  = 3;
	semop_ret =  semop(semget_fd, &my_sembuf, 1);
	perror("semop"" after upate +1");
}
