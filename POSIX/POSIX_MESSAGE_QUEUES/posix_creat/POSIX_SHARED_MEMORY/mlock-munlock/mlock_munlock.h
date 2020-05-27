/**********************************************/
/* Author       : Naveenkumar N               */
/* Date         : 23-05-2020                  */
/* Filename     : mlock_munlock.h             */
/* Description  : protect a maped file        */
/**********************************************/


#define SHELL_CMD "cat /proc/%d/maps | grep zero"
#define BUFFER_SIZE (sizeof(SHELL_CMD))

#ifndef MLOCK_MUNLOCK_H
#define MLOCK_MUNLOCK_H

/* Included header files */

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

/* Macro Definitions */

/* Functions prototype */


/* user defined datatype definitions */

#endif //MLOCK_MUNLOCK_H
