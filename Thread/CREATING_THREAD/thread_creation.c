/*********************************************/
/* Author       : Navin kumar.N              */
/* Date         : 6-02-2019                  */
/* Filename     : THREAD_CREAT.C             */
/* Description  : CREAT THREAD  In "THREAD"  */
/*********************************************/


#include   "header.h"


void * thread_fun(void *);

int main()
{
  int fd,data;

  pthread_t  thread_creat;
  //GET INPUT FROM THE USER//
  scanf("%d",&data);

  //THREAT CREATION USING PTHREAD_CREAT//
  fd=pthread_create(&thread_creat,NULL,thread_fun,&data);
  //FUNCTION CALL//
  thread_fun(&data);

}
void *thread_fun(void *data)
{
  //TYPE CASTING//
  int *colect_data =(int *)data;
  int a;
  //FOR LOOP CONDITION//
  for(a=0;a<=(*colect_data);a++)
    printf("%d\n",a);
}
