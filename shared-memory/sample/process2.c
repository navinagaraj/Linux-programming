/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 19-05-2020                  */
/* Filename     : process2                    */
/* Description  : create a shared-memory      */
/**********************************************/
#include "shm_sys_v.h"
int main(){ 
	int shmget_fd,shmget_dt;
	char buffer[20];
	char *ptr;
	shmget_fd =  shmget(200, 4096, 0);
	perror("shmget");
	ptr = shmat(shmget_fd, NULL, 0);
	printf("ptr addres = %p\n",ptr);
	perror("shmat");
	strcpy(buffer,ptr);
	printf("%s\n",buffer);
	shmdt(ptr);
	perror("shmdt");
}
