/*****************************************/
/* Author       : Navin kumar.N          */
/* Date         : 25-01-2019             */
/* Filename     : READMI.txt             */
/* Description  : ls.c file  In " LS "   */
/*****************************************/

#include  "header.h"

struct dirent *data;

int main(int argc,char *dat[])
/*command line argument */
{
  int a=0,b=0;
  DIR *n,*p;
  char *ptr,ptr1;
  ptr=dat[1];

  if(argc==1)
  {
    n=opendir("./");
    /*The   opendir()  function  opens  a  directory stream corresponding to  the  directory*/ 
  }
  else if(argc >1)
  {
   n=opendir(ptr);
   if(n==0)
   {
     printf("Not directory");
     exit(0);
     /* exit from the program*/
   }
  }
  data = readdir(n);
  /* The fnction returns a pointer to a strcture next ditectory stream point */ 
  for(;data !=NULL;) 
  {
    if(strcmp(data->d_name,".")==0||strcmp(data->d_name,"..")==0)
      {
        /*To avoiding the "." and ".." from the data.*/
      }
    else
      printf("%s\n",data->d_name);
      /*printing data in the struct*/
  data=readdir(n);
  /*The fnction returns a pointer to a strcture next ditectory stream point*/
  }
  closedir(n);
  /*The  closedir  function closes the directory stream*/
}
