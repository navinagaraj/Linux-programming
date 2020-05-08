/***************************************/
/* Author	:Naveenkumar N         */
/* Date		:05-05-2020            */
/* Filename	:error_log.h           */
/* Description	:error_log             */
/***************************************/

#ifndef MAKE_H
#define MAKE_H

/* Included header files */

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_WRITE  siz_write = write(open_fd, str_all_2, strlen(str_all_2));




/* Macro Definitions */

/* Functions prototype */


/* user defined datatype definitions */
char str_all[8192];

time_t t ;
struct tm *tm;


#endif //MAKE_H
