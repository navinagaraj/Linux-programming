#ifndef MY_ERROR_H
#define MY_ERROR_H

#include <error.h>



#ifdef ERROR_MESSAGE
#define my_error(s) perror(s)
#else
#define my_error(s) 
#endif //ERROR_MESSAGE

#endif //MY_ERROR_H
