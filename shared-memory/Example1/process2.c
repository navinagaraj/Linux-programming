/*----------------------------------------------------SCHOOL-OF-LINUX-------------------------------------------------------------
-------------------------------------------------NAME.OF.AUTHOR:NAVIN KUMAR.N-----------------------------------------------------
--------------------------------------------------DATE.OF.CREATED:22-01-2019------------------------------------------------------*/


#include  <stdio.h>
#include  <stdio.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <error.h>
#include  <sys/stat.h>
#include  <string.h>

int main()
{
   int shmid1;
   char data[100];
   char *data_ptr;

   shmid1 = shmget(1002, 8192, 0); 
   //shmid1 = shmget(The value argument key,page size).

   perror("shmget: ");
   //perror print the final execution.
              
   data_ptr = shmat(shmid1, NULL,0);
   //returns the virtual address where the shared memory is mapped.
   perror("shmat: ");
   //perror print the final execution.
                  
   printf("%p\n",data_ptr);

   strcpy(data, data_ptr);
   //copy some data into shared memory is the address returned from shmat().

   printf("%s\n",data);

   shmdt(data_ptr);
   //The address of colling memory.

   perror("shmdt: ");
   //perror print the final execution.

   return 0;
}
