/**********************************************/
/* Author       : Navin kumar.N               */
/* Date         : 30-04-2020                  */
/* Filename     : creat_signal.H              */
/* Description  : HEADER FILE"creat_signal.h" */
/**********************************************/

#ifndef creat_signal_h
#define creat_signal_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


typedef void (*sighandler_t)(int);
void my_sig_handler(int );
#endif  //creat_signal_h
