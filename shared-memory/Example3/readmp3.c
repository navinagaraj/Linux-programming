/*-----------------------------------------------------SCHOOL-OF-LINUX-----------------------------------------------------------*/
/*----------------------------------------------NAME.OF.AUTHOR: NAVIN KUMAR.N----------------------------------------------------*/
/*-----------------------------------------------DATE.OF.CREATED :22.01.2019-----------------------------------------------------*/




#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>

char buffer[1795463];
int main()
{
   int ret_val;
   int fd,fd1;
   ssize_t ret_read,ret_write;

   ret_val = mknod("songpath",0764|S_IFIFO,0);
   //ret_val=mkdir(pathname,mode,devise).
   perror("mknod: ");
   //perror print the final execution.

   fd=open("songpath",O_RDONLY);
   //fd=open(pathname,mode);
   perror("open: ");
   //perror print the final execution.

   ret_read=read(fd,buffer,1795463);
   //ret_read=read(filediscriptor,data,size),
   perror("read: ");
   //perror print the final execution.

   fd1=open("petta.mp3",O_CREAT|O_RDWR,0764);
   //fd1=open(pathname,mode,permisions).
   perror("open: ");
   //perror print the final execution.

   ret_write=write(fd1,buffer,1795463);
   //ret_write=write(filediscriptor,data,size to write).
   perror("write: ");
   //perror print the final execution.
   close (fd);
   //shoud close fd after finish all works.
   close (fd1);
   //shoud close fd after finish all works.
}
