#ifndef _SHELL_H_
#define _SHELL_H_

/** ##### environ var #######*/

extern char **environ;

/** ###### MACROS #####*/

#define BUFSIZE 1024
#define DELIM "\t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**##### LIBS USED ######*/

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
