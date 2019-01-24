/*-----------------------------------------------------SCHOOL-OF-LINUX-----------------------------------------------------------*/
/*----------------------------------------------NAME.OF.AUTHOR: NAVIN KUMAR.N----------------------------------------------------*/
/*-----------------------------------------------DATE.OF.CREATED :22.01.2019-----------------------------------------------------*/



#include  <stdio.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <error.h>
#include  <sys/stat.h>
#include  <string.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <fcntl.h>

int main()
{
    int      shmid1,fd;
    char     *data_ptr;
    ssize_t  ret_read;
    char     buffer[100]; 

    shmid1 = shmget(1002, 8192, IPC_CREAT | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    //shmid1 = shmget(the value of argument key,page size,creat a new segment and execute permissions).

    perror("shmget: ");
    //perror print the final execution.

    data_ptr = shmat(shmid1, NULL,0);
    //returns the virtual address where the shared memory is mapped.

    perror("shmat: ");
    //perror print the final execution.

    printf("%p\n",data_ptr);
                    
    fd=open("/home/mani/vino_sir/system_call/i_p_c/communication/shared memory/Examples-programs/EXAMPLE_1/prog_expl",O_RDONLY);
    //location of the file whare you need to get data.

    ret_read=read(fd,buffer,100);
    //reading data from fd(file-discreptor) and save in buffer.
                          
    strcpy(data_ptr,buffer);
    //copy some data into shared memory is the address returned from shmat().

    shmdt(data_ptr);
    //the virtul address mapped to shared memory has to be detached after usage is done, so shmdt is used.

    perror("shmdt: ");
    //perror print the final execution.

    return 0;
}
