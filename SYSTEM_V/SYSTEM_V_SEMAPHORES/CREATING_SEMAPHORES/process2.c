/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 25-05-2020                  */
/* Filename     : process2.c                  */
/* Description  : creating semaphores         */
/**********************************************/


#include "my_header.h"


int main(){
	int semget_fd, semctl_ret, semop_ret, open_fd, close_ret;
	ssize_t ret_read;
	char buffer[4096];

	struct sembuf my_sembuf;

	my_sembuf.sem_num =  3;
	my_sembuf.sem_op  = -1;

	semget_fd =  semget(18, 5, IPC_CREAT|0644);
	perror("semget");
	semctl_ret = semctl( semget_fd, 3, SETVAL,3);
	perror("semctl");
	semop_ret =  semop(semget_fd, &my_sembuf, 1);
	perror("semop");

	printf("PID = %d is started to reading\n",getpid());

	sleep(20);

	open_fd =  open("./my_data.txt", O_RDONLY);
	perror("open");
	ret_read = read( open_fd, buffer, 30);
	perror("read");

	printf("----Data in buffer----\n");
	printf("%s\n",buffer);
	close_ret =  close(open_fd);
	perror("close");

	printf("PID = %d is complited  reading\n",getpid());

	my_sembuf.sem_op  = 1;
	semop_ret =  semop(semget_fd, &my_sembuf, 1);
	perror("semop"" after upate +1");
}
