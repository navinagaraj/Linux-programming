#include "multi_thread.h"



pthread_mutex_t lock;//function shall initialize the mutex referenced by mutex with attributes specified by " lock "//

int a;
void * thread_1_fun (void *);
void * thread_2_fun (void *);
void * thread_3_fun (void *);

int main(){
	int fd_1,fd_2,fd_3;
	pthread_t thread_1,thread_2,thread_3;
	pthread_attr_t thread_struct;

	pthread_attr_init(&thread_struct);// function  initializes  the  thread  attributes  object pointed to by (Thread_struct) with default attribute values//

	if(pthread_mutex_init(&lock, NULL) == 0){
		printf("pthread_mutex_init\n");
	}else{
		printf("pthread_mutex_not_init\n");}

	fd_1 = pthread_create(&thread_1,&thread_struct,thread_1_fun,NULL);
	perror("pthread_create");// the last error encountered during a call to a system or library function//
	fd_2 = pthread_create(&thread_2,&thread_struct,thread_2_fun,NULL);
	perror("pthread_create");// the last error encountered during a call to a system or library function//
	fd_3 = pthread_create(&thread_3,&thread_struct,thread_3_fun,NULL);
	perror("pthread_create");// the last error encountered during a call to a system or library function//
	pthread_join(thread_1,NULL);//function waits for the thread specified by thread to terminate//
	pthread_join(thread_2,NULL);//function waits for the thread specified by thread to terminate//
	pthread_join(thread_3,NULL);//function waits for the thread specified by thread to terminate//
	//return_val = pthread_mutex_destroy(&lock);
	if(pthread_mutex_destroy(&lock) == 0){
		printf("pthread_mutex_destroyed\n");
	}else{
		printf("pthread_mutex_Not_destroyed\n");}
}

void * thread_1_fun (void *data){

	pthread_mutex_lock(&lock);
	int stack = 10;
	 a = 10;
	printf("Address = %p Value = %d\n",&a,a);
	printf("stack Address = %p Value = %d\n",&stack,stack);
	pthread_mutex_unlock(&lock);
	printf("Source:%s/Function in Thread_1\n",__FILE__);
}

void * thread_2_fun (void *data){
	pthread_mutex_lock(&lock);
	int stack = 20;
	 a = 20;
	printf("Address = %p Value = %d\n",&a,a);
	printf("stack Address = %p Value = %d\n",&stack,stack);
	pthread_mutex_unlock(&lock);
	printf("Source:%s/Function in Thread_2\n",__FILE__);
}
void *thread_3_fun (void *data){
	printf("Source:%s/Function in Thread_3\n",__FILE__);
	printf("Address = %p Value = %d\n",&a,a);
}
