/* _________________________________ */
/*| Author     :Navin kumar.N       |*/
/*| Date       :23-01-2019          |*/
/*| File-name  :program1.c          |*/
/*| Description:Using posix in mmap |*/
/*|_________________________________|*/


#include "header.h"
int main()
{
  char buffer[20]={"Data from process1"};
  int fd,fd1,b,a,i;
  char *ptr;
  ssize_t ret_write;
  fd=shm_open("/data",O_CREAT|O_RDWR,0644);
  perror("shm_open  ");
  ret_write=write(fd,buffer,20);

  ptr=mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  perror("mmap ");

  b=msync(ptr,20,MS_SYNC);
  a=munmap(ptr,20);
  return 0;
}
