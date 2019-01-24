/*-----------------------------------------------------SCHOOL-OF-LINUX-----------------------------------------------------------*/
/*----------------------------------------------NAME.OF.AUTHOR: NAVIN KUMAR.N----------------------------------------------------*/
/*-----------------------------------------------DATE.OF.CREATED :22.01.2019-----------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>
#include<error.h>

char message3[] = "This is from process3\n";
int main()
{
    int ret;
    mqd_t mqopen;
    struct mq_attr my_attr;

    mqopen = mq_open("/process3", O_CREAT|O_RDWR,0644,NULL);
    //To creat new POSIX message que name of msgqueue must be starting with " / " slash.
    perror("mq_open: ");
    // perror print the last execution.

    ret = mq_send(mqopen, message3, strlen(message3)+1, 100);
    //ret=mq_send(message que fd(Descripetor),message,message length,message priority).
    perror("mq_send: ");
    // perror print the last execution.

    ret = mq_close(mqopen);
    // close a message queue descriptor
    perror("mq_close: ");
    // perror print the last execution.
}
