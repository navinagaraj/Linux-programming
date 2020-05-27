#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdio.h>
#include "my_error.h"
#include <string.h>


//struct mq_attr {
//	          long mq_flags;       /* Flags: 0 or O_NONBLOCK */
//		  long mq_maxmsg;      /* Max. # of messages on queue */
//		  long mq_msgsize;     /* Max. message size (bytes) */
//		  long mq_curmsgs;     /* # of messages currently in queue */
//	       };



char str[8192];

int main(){

	int mq_open_ret,mq_send_ret,msg_prio;
	ssize_t my_mq_receive;
	struct mq_attr my_mq_attr;

//	my_mq_attr.mq_flags   = 0;
//	my_mq_attr.mq_maxmsg  = 50;
//      my_mq_attr.mq_msgsize = 2048;
		

	 //mqd_t mq_open(const char *name, int oflag, mode_t mode,struct mq_attr *attr);

	mq_open_ret = mq_open("/my_posix", O_RDWR);
	my_error("mq_open");

	if(mq_open_ret == -1){
		printf("mq_open Error\n");
	}else{
		printf("mq_open sucess\n");
	}
	//ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,size_t msg_len, unsigned int *msg_prio);
	my_mq_receive =  mq_receive(mq_open_ret,str,8192, &msg_prio);
	my_error("mq_receive");
	printf("%s\n",str);
}
