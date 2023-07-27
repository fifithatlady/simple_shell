#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Commented out common definitions to avoid duplication
#define BUFFER 1024
#define TRUE 1
#define PROMPT "$ "
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create child process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;
*/

/**
 * struct list_s - a linked list of variables
 * @value: value
 * @next: next node
 * Description: linked list struct for variables.
**/
typedef struct list_s
{
    char *value;
    struct list_s *next;
} list_s;

/**
 * struct built_s - a linked list of builtins environment
 * @name: builtin names
 * @p: a pointer
 *
 * Description:a a typedef struct for builtin functions.
**/
typedef struct built_s
{
    char *name;
    int (*p)(void);
} built_s;

/* Common function prototypes with different names */
void prompt(int fd, struct stat buf);  // Commented out in the first header
char *_getline(FILE *fp);  // Commented out in the first header

/* Function prototypes from the second header */
char **tokenizer(char *str);
char *_which(char *command, char *fullpath, char *path);
int child(char *fullpath, char **tokens);
void errors(int error);

/* Common function prototypes with different names */
void _puts(char *str);  // Commented out in the first header
int _strlen(char *s);  // Commented out in the first header
int _strcmp(char *name, char *variable, unsigned int length);  // Commented out in the first header
int _strncmp(char *name, char *variable, unsigned int length);  // Commented out in the first header
char *_strcpy(char *dest, char *src);  // Commented out in the first header

/* Function prototypes from the second header */
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **tokens);
int shell_num_builtins(built_s builtin[]);

/* Common function prototypes with different names */
char *_getenv(const char *name);  // Commented out in the first header
char **copy_env(char **environ_copy, unsigned int environ_length);  // Commented out in the first header
list_s *pathlist(char *variable, list_s *head);  // Commented out in the first header

/* Common function prototypes with different names */
void free_all(char **tokens, char *path, char *line, char *fullpath, int flag);  // Commented out in the first header
void free_dp(char **array, unsigned int length);  // Commented out in the first header

#endif /* SHELL_H */

