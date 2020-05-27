/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 22-05-2020                  */
/* Filename     : mprotect.h                  */
/* Description  : protect a maped file        */
/**********************************************/


#define SHELL_CMD "cat /proc/%d/maps | grep zero"
#define BUFFER_SIZE (sizeof(SHELL_CMD))

#ifndef MPROTECT_H
#define MPROTECT_H

/* Included header files */

#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

/* Macro Definitions */

/* Functions prototype */


/* user defined datatype definitions */

#endif //MPROTECT_H
