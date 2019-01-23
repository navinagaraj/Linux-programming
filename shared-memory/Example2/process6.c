#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<error.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

char Buffer1 [8192]  = "";
char Buffer2 [8192]  = "";
char Buffer3 [8192]  = "";
char Buffer4 [8192]  = "";
char Buffer5 [8192]  = "";
char allbuffer[8192] = "";

int main()
{
    int ret;
    mqd_t mqopen;
    ssize_t recv;

    unsigned int prio;

    struct mq_attr my_attr;

    int shmid1;
    char *data_ptr;
    shmid1 = shmget(101, 8192, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH);
    //shmid1=shmget(The value ofargument key,size of page,permission access segment).

    perror("shmget: ");
    // perror print the last execution.

    mqopen = mq_open("/process1", O_RDWR);
    //While opening mq_open 2 perameters is enough 1 is (name) and 2 is (flags).

    perror("mq_open: ");
    // perror print the last execution.

    recv = mq_receive(mqopen, Buffer1, 8192, &prio);
    //recv=mq_receive(file description,message,message length,priority).
    perror("mq_receive: ");
    // perror print the last execution.
                                     
    mq_getattr(mqopen, &my_attr);
    //mq_getattr(file description,buffer pointer by attr is define).

    ret = mq_close(mqopen);
    //close message queue descriptor.

    perror("mq_close: ");
    // perror print the last execution.

    mqopen = mq_open("/process2", O_RDWR);
    //While opening mq_open 2 perameters is enough 1 is (name) and 2 is (flags).

    perror("mq_open: ");
    // perror print the last execution.

    recv = mq_receive(mqopen, Buffer2, 8192, &prio);
    //recv=mq_receive(file description,message,message length,priority).

    perror("mq_receive: ");
    // perror print the last execution.
                                                   
    mq_getattr(mqopen, &my_attr);
    //mq_getattr(file description,buffer pointer by attr is define).

    ret = mq_close(mqopen);
    //close message queue descriptor.

    perror("mq_close: ");
    // perror print the last execution.

    mqopen = mq_open("/process3", O_RDWR);
    //While opening mq_open 2 perameters is enough 1 is (name) and 2 is (flags).

    perror("mq_open: ");
    // perror print the last execution.

    recv = mq_receive(mqopen, Buffer3, 8192, &prio);
    //recv=mq_receive(file description,message,message length,priority).

    perror("mq_receive: ");
    // perror print the last execution.
                                            
    mq_getattr(mqopen, &my_attr);
    //mq_getattr(file description,buffer pointer by attr is define).

    ret = mq_close(mqopen);
    perror("mq_close: ");
    // perror print the last execution.

    mqopen = mq_open("/process4", O_RDWR);
    //While opening mq_open 2 perameters is enough 1 is (name) and 2 is (flags).

    perror("mq_open: ");
    // perror print the last execution.

    recv = mq_receive(mqopen, Buffer4, 8192, &prio);
    //recv=mq_receive(file description,message,message length,priority).

    perror("mq_receive: ");
    // perror print the last execution.
                                                                   
    mq_getattr(mqopen, &my_attr);
    //mq_getattr(file description,buffer pointer by attr is define).

    ret = mq_close(mqopen);
    //close message queue descriptor.

    perror("mq_close: ");
    // perror print the last execution.

    mqopen = mq_open("/process5", O_RDWR);
    //While opening mq_open 2 perameters is enough 1 is (name) and 2 is (flags).

    perror("mq_open: ");
    // perror print the last execution.

    recv = mq_receive(mqopen, Buffer5, 8192, &prio);
    //recv=mq_receive(file description,message,message length,priority).

    perror("mq_receive: ");
    // perror print the last execution.

    mq_getattr(mqopen, &my_attr);
    //mq_getattr(file description,buffer pointer by attr is define).
    ret = mq_close(mqopen);                           
    //close message queue descriptor.
    perror("mq_close: ");
    // perror print the last execution.

    int i=0,j=0,loop;
    for(loop=0;loop<=4;loop++)       
    {                        
      if(loop==0)
      {
        for(i=0;Buffer1[i]!=0;i++,j++)       
          allbuffer[j]=Buffer1[i];
      }
      else if(loop==1)
      {
        for(i=0;Buffer2[i]!=0;i++,j++)
          allbuffer[j]=Buffer2[i];
      }
      else if (loop==2)
      {
        for(i=0;Buffer3[i]!=0;i++,j++)
          allbuffer[j]=Buffer3[i];
      }
      else if (loop==3)
      {
        for(i=0;Buffer4[i]!=0;i++,j++)
          allbuffer[j]=Buffer4[i];
      }
      else if (loop==4)
      {
        for(i=0;Buffer5[i]!=0;i++,j++)
          allbuffer[j]=Buffer5[i];
      }
    }
    data_ptr = shmat(shmid1, NULL,0);
    perror("shmat: ");
    // perror print the last execution.
    printf("%p\n",data_ptr);
    strcpy(data_ptr, allbuffer);
    shmdt(data_ptr);
    perror("shmdt: ");
    // perror print the last execution.
    mq_unlink("/posix1");
    return 0;
}
