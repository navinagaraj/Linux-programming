/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 19-05-2020                  */
/* Filename     : process1                    */
/* Description  : create a shared-memory      */
/**********************************************/
#include "shm_sys_v.h"
int main(){ 
	int shmget_fd,shmget_dt;
	char buffer[20]="hi Shared-memory";
	char *ptr;
	shmget_fd =  shmget(200, 4096, IPC_CREAT|0644);//0644 = ( 6-> user = RW, 4-> group = R, 4-> others = R)
	perror("shmget");
	ptr = shmat(shmget_fd, NULL, SHM_RND);
	printf("ptr addres = %p",ptr);
	perror("shmat");
	strcpy(ptr,buffer);
	shmdt(ptr);
	perror("shmdt");
}
