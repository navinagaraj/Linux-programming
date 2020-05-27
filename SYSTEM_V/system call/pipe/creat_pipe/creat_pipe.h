/*******************************************/
/* Author       : Navin kumar.N            */
/* Date         : 30-04-2020               */
/* Filename     : creat_pipe.H             */
/* Description  : HEADER FILE  "pipe"      */
/*******************************************/

#ifndef creat_pipe_h
#define creat_pipe_h

#define error_log 1 //1 for without error_log. 0 for with error_log//


#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>		
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
#endif //creat_pipe_h
