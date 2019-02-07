/******************************************************/
/* Author       : Navin kumar.N                       */
/* Date         : 7-02-2019                           */
/* Filename     : README.TXT                          */
/* Description  : EXPLINATION  OF THREAD AND MUTEXES  */
/******************************************************/


THREAD :

	we describe two tools that threads can use to synchronize their actions: mutexes and condition variables. Mutexes allow threads to synchronize their use of a shared resource, so that, for example, one thread doesn’t try to access a shared variable at the same time as another thread is modifying it. Condition vari- ables perform a complementary task: they allow threads to inform each other that a shared variable (or other shared resource) has changed state.

Statically Allocated Mutexes:

	A mutex can either be allocated as a static variable or be created dynamically at run time , in a block of memory allocated via malloc(). Dynamic mutex cre-ation is somewhat more complex, and we delay discussion of it until Section. A mutex is a variable of the type pthread_mutex_t. Before it can be used, a mutex must always be initialized. For astatically al located mutex, we can  this by assigning it the value PTHREAD_MUTEX_INITIALIZER.

			
