#include "sbrk.h"

int main()
{
	void * ptr,* ptr_1;
	char a =1;

	ptr = sbrk(0);
	printf("Break point address = %p\n",ptr);
	printf("Parent id = %d\n",getpid());
	//sleep(30);


	ptr = sbrk(135168);
	printf("Break point address = %p\n",ptr);
	//sleep(30);

	printf("%p\n",&ptr);

	printf("%p\n",&ptr+4096);

	


}
