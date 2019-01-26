/*****************************************/
/* Author       : Navin kumar.N          */
/* Date         : 25-01-2019             */
/* Filename     : READMI.txt             */
/* Description  : ls.c file  In " LS "   */
/*****************************************/


#include  "header.h"
struct dirent *data;

int main(int argc,char *dat[])
/*command line interface*/
{
  int a=0,b=0;
  DIR *n,*p;
  char *ptr,ptr1;
  ptr=dat[1];
  if(argc==1)
  {
    n=opendir("./");
    /* The   opendir function  opens  a  directory
       stream corresponding to  the  directory */
  }
  else if(argc >1)
  {
   n=opendir(ptr);
   if(n==0)
   {
     printf("Not directory");
     exit(0);
     /*Exit from the program*/
   }
  }
  data = readdir(n);
  /*read a directory function returns a pointer */
  for(;data !=NULL;)
  {
    if(strcmp(data->d_name,".")==0||strcmp(data->d_name,"..")==0)
      {
        /*To avoiding the "." and ".."*/
      }
    else
      printf("%s\n",data->d_name);
  data=readdir(n);
  /*read a directory function returns a pointer */
  }
  closedir(n);
  /*close a directory*/
}
