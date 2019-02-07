/*******************************************/
/* Author       : Navin kumar.N            */
/* Date         : 7-02-2019                */
/* Filename     : MUTEXES.c                */
/* Description  : THREAD AND MUTEXES       */
/*******************************************/

#include  "header.h"

static int glob_data=0;

static pthread_mutex_t const_data =PTHREAD_MUTEX_INITIALIZER;

//FUNCTION PROTOTYPE//
void *function_call(void *);

int main()
{
  pthread_t thread_1,thread_2;

  int data,fd;
  //GET INPUT FROM THE USER SAVE IN DATA//
  scanf("%d",&data);

  //CREATING THREAD 1 SEND DATA TO THE FUNCTION//
  fd  = pthread_create(&thread_1,NULL,function_call,&data);
  perror("fd");

  //CREATING THREAD 2 SEND DATA TO THE FUNCTION//
  fd  = pthread_create(&thread_2,NULL,function_call,&data);
  perror("fd");
  //FUNCTION CALL FOR THREAD 1//
  fd  = pthread_join(thread_1,NULL);

  //FUNCTION CALL FOR THREAD 2//
  fd  = pthread_join(thread_2,NULL);

  //PRINTING THE GLOB_DATA VALUE//
  printf("glob_data =%d\n",glob_data);
}

void *function_call(void *all_data)
{
  int *count =  (int *)all_data;
  int a,b,fd;


  for(a=0;a<*count;a++)
  {
    //LOCKING THE PTHREAD USING MUTEX_LOCK//
    fd  = pthread_mutex_lock(&const_data);

    b = glob_data;
    b++;
    glob_data=b;

    //UNLOCK THE PTHREAD USING MUTEX_LOCK//
    fd  = pthread_mutex_unlock(&const_data);
  }
}
