#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <error.h>
#include <string.h>

struct mymsg {
	long mtype;
	char mtext[200];
};
char str1[]="my data from str1\n";
char str2[]="my data from str2\n";
char str3[]="my data from str3\n";

int main(){

	int mesg_id,msgsnd_return;

	struct mymsg my_data1,my_data2,my_data3;
	my_data1.mtype  = 1;
	my_data2.mtype  = 2;
	my_data3.mtype  = 3;


	strncpy(my_data1.mtext,str1,strlen(str1)+1);
	strncpy(my_data2.mtext,str2,strlen(str2)+1);
	strncpy(my_data3.mtext,str3,strlen(str3)+1);

	//int msgget(key_t key, int msgflg);
	mesg_id = msgget(103,IPC_CREAT|0644);//creating a msgget//
	perror("msgget");
	//int msgsnd(int msqid , const void * msgp , size_t msgsz , int msgflg );
	msgsnd_return = msgsnd(mesg_id, &my_data1, strlen(str1)+1, 0);//sending a msgsnd//
	perror("msgsnd");
	msgsnd_return = msgsnd(mesg_id, &my_data2, strlen(str2)+1, 0);//sending a msgsnd//
	perror("msgsnd");
	msgsnd_return = msgsnd(mesg_id, &my_data3, strlen(str3)+1, 0);//sending a msgsnd//
	perror("msgsnd");
}
