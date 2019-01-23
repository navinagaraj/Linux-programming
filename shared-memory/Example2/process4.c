/*-----------------------------------------------------SCHOOL-OF-LINUX-----------------------------------------------------------*/
/*----------------------------------------------NAME.OF.AUTHOR: NAVIN KUMAR.N----------------------------------------------------*/
/*-----------------------------------------------DATE.OF.CREATED :22.01.2019-----------------------------------------------------*/


#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<error.h>

char message4[] = "This is from process4\n";

int main()
{
    int ret;
    mqd_t mqopen;
    struct mq_attr my_attr;

    mqopen = mq_open("/process4", O_CREAT|O_RDWR,0644,NULL);
    //To creat new POSIX message que name of msgqueue must be starting with " / " slash.
    perror("mq_open: ");
    // perror print the last execution.

    ret = mq_send(mqopen, message4, strlen(message4)+1, 100);
    //ret=mq_send(message que fd(Descripetor),message,message length,message priority).

    perror("mq_send: ");
    // perror print the last execution.

    ret = mq_close(mqopen);
    // close a message queue descriptor
    perror("mq_close: ");
    // perror print the last execution.
}
