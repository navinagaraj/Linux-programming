/***************************************/
/* Author	:Naveenkumar N         */
/* Date		:05-05-2020            */
/* Filename	:error_log.c           */
/* Description	:error_log             */
/***************************************/

#include "error_log.h"

char* dty_function();
int main(){
	
	int open_fd,*ptr,open_fd_1;
	ssize_t siz_write;
	char *str_all_1[8192];
	char str_all_2[8192];

	//char *strcat(char *dest, const char *src);
	
	//strcat(str_all_1,str_all_2);
	//printf("STRCAT = %s\n",str_all_1);
	
	open_fd =  open("./error_log.txt",O_RDWR|O_APPEND);
	perror("open");
	if(open_fd > 0){
		sprintf(str_all_2,"%s open_fd: sucess\n",dty_function());	
	}else{
		sprintf(str_all_2,"%s open_fd: Error to creat a file\n",dty_function());	
	}
	FILE_WRITE;
	//sprintf(str_all_2,"%s\n",dty_function());	
	//FILE_WRITE;
        close(open_fd);
//	sleep(30);
}



char *dty_function(){
	 	t = time(NULL);
		tm = localtime(&t);
		sprintf(str_all,"%d-%02d-%02d %02d:%02d:%02d  %s",tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec ,getenv("USER"));
		return str_all;

}
