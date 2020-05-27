/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 22-05-2020                  */
/* Filename     : mprotect.c                  */
/* Description  : protect a maped file        */
/**********************************************/

#include "mprotect.h"


int main(){
	int mprotect_fd;
	char *ptr;
	char buffer[BUFFER_SIZE];


	 snprintf( buffer, BUFFER_SIZE, SHELL_CMD, getpid() );

	 ptr = mmap( NULL, 4096, PROT_NONE, MAP_ANONYMOUS|MAP_SHARED, -1, 0);
	 if(ptr == MAP_FAILED)
		 perror("mmap");
	 printf("Before  memory protection of the mapping \n");
	 system(buffer);
	 if(mprotect( ptr, 4096, PROT_READ|PROT_WRITE|PROT_EXEC)  == -1)
	 perror("mprotect");
	 printf("After  memory protection of the mapping \n");
	 system(buffer);
}
