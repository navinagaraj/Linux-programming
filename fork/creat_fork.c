#include "creat_fork.h"
int main(){
	int fd;
	int  status;


	fd = fork();//create a child process//
	if(fd > 0){//On success, the PID of the child process is returned in the parent//
		printf("PID = %d  PPID = %d I am Parent process\n",getpid(),getppid());//getpid, getppid-get process identification//
		wait(&status);// wait for process to change state//
	printf("%d\n",WEXITSTATUS(status));//(((status) & 0xff00)>> 8));
	}else if(fd == 0){//On success, the PID of the child process is returned in the parent//
		printf("PID = %d  PPID = %d I am child  process\n",getpid(),getppid());
		return 10;}
	else{//On failure, -1 is returned in the par‐ent, no child process is created//
		printf("No child process is created\n");}
}
