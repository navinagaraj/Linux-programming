#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <error.h>
unsigned char song_data[1795463];
int main()
{
    int retval;
    int fd,fd1;
    ssize_t ret_write,ret_read;
    fd= open("./song.mp3",O_RDONLY);
    //fd=open(file pathname,flags (read,write like that)).
    perror("open: ");  
    //perror print the final execution.
    ret_read = read(fd,song_data,1795463);
    //ret_read=read(fd(filediscripter),buffer,size).
    perror("read: ");
    //perror print the final execution.

    printf("%s\n",song_data);

    fd1=open("songpath",O_WRONLY);
    //fd1=open(pathname,flags(read,write)).
    perror("Open: ");
    //perror print the final execution.

    ret_write=write(fd1,song_data,1795463);
    //ret_write=(filediscriptor,buffer,size).
    perror("write: ");
    //perror print the final execution.

    close(fd);
    //shoud close fd after finish all works.
    close (fd1);
    //shoud close fd after finish all works.
}
