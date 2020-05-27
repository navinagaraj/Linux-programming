#include "creat_signal.h"

int main(){
	int num = 0;
	sighandler_t old_handler;

	old_handler = signal(8,my_sig_handler);

	while(1){

		printf("Function from = %s :process_id = %d\n",__func__,getpid());
		num++;
		if(num == 20){
			old_handler = signal(8,old_handler);}
	}


}


void my_sig_handler(int signal_num){

	printf("my signal_num = %d\n",signal_num);
}
