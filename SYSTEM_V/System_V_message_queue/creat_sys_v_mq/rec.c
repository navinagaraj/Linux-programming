#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <error.h>
#include <string.h>

struct msgbuf{
       	long mtype;/* message type, must be > 0 */
	char mtext[200];    /* message data */
};



int main(){
	
	int mesg_id;
	ssize_t fd;
	struct msgbuf my_data1,my_data2,my_data3;
	 //ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)

	mesg_id = msgget(103,IPC_CREAT|0644);
	perror("msgget");

	fd = msgrcv(mesg_id, &my_data1, 200, 0, 1);
	perror("msgrcv");
	printf("%ld  %s\n",my_data1.mtype,my_data1.mtext);

	fd = msgrcv(mesg_id, &my_data2, 200, 0, 2);
	perror("msgrcv");
	printf("%ld  %s\n",my_data2.mtype,my_data2.mtext);

	fd = msgrcv(mesg_id, &my_data3, 200, 0, 3);
	perror("msgrcv");
	printf("%ld  %s\n",my_data3.mtype,my_data3.mtext);
}
