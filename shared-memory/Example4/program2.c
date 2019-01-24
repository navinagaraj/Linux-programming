/* _________________________________ */
/*| Author     :Navin kumar.N       |*/
/*| Date       :23-01-2019          |*/
/*| File-name  :program1.c          |*/
/*| Description:Using posix in mmap |*/
/*|_________________________________|*/


#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <error.h>
#include <unistd.h>
int main()
{
  char buffer[20];
  int fd,a,b,inl;
  char *ptr;
  ssize_t ret_read;
  fd=shm_open("/data",O_RDONLY,0644);
  perror("shm_open");
  ret_read=read(fd,buffer,20);
  perror("write ");
  ptr=mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  b=msync(ptr,20,MS_SYNC);
  a=munmap(ptr,20);
  printf("%s\n",buffer);
}
