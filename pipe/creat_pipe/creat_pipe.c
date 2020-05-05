#include "creat_pipe.h"


int main(){
	
	char buffer_write[]="Data is correct\n",buffer_read[20],*ptr,fork_fd;	
	int fd,pipe_fd[2];//pipefd[0] refers to the read end of the pipe.pipefd[1] refers to the  write//
	ssize_t write_fd ,read_fd;
	int state_wait;


	ptr = (char *)malloc(30);
	#if  error_log 
	perror("malloc");//Allocate and free dynamic memory//
	#else
	#if(error_log == 0)
	perror("malloc");
	if(ptr == 0){
		printf("Unable to allocate memory space\n");}
	else{
		printf("sucessfully allocate memory space\n");}
	//perror("strcpy");
	printf("Size of malloc allocates %ld bytes\n",sizeof(ptr));
	#endif
	#endif
	fd = pipe(pipe_fd);//creates  a pipe//
	#if error_log
	perror("pipe");
	#else
	#if (error_log == 0)
	printf("Pipe file descriptor = %d\n",fd);
	perror("pipe");
	#endif
	#endif

	fork_fd = fork();
	if(fork_fd > 0){
		write_fd = write(pipe_fd[1],buffer_write,strlen(buffer_write)+1);
	}
	else if(fork_fd == 0){
		read_fd = read(pipe_fd[0],ptr,20);
	printf("String : %s",ptr);
	}
	else{
		printf("fork Not created\n");}
	#if(error_log == 0)
	printf("write_fd = %ld\n",write_fd);
	#endif
	#if(error_log == 0)
	printf("read_fd = %ld\n",read_fd);
	#endif
	free(ptr);
	perror("free");
}
