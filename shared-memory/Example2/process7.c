#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
   int shmid1;
   char data[8148];
   char *data_ptr;
   shmid1 = shmget(101, 8192, 0);
   //shmid1=shmget(shared memory segment argument key,page size,flags)
   perror("shmget: ");
   // perror print the last execution.
                                   
   data_ptr = shmat(shmid1, NULL,0);
   //data_ptr=shmat(segment identified,null,page-aligned address).
   perror("shmat: ");
   // perror print the last execution.
                                             
   printf("%p\n",data_ptr);
   printf("%p\n",main);
   strcpy(data, data_ptr);
   //strcpy(destination,source).
   printf("%s\n",data);
   shmdt(data_ptr);
   //the system chooses a suitable address.
   perror("shmdt: ");
   // perror print the last execution.
   return 0;
}
