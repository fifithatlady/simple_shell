                                      ##SIMPLE SHELL ALX PROJECT 2023#7#CHT15#


#this simple shell is using the following lit of allowed funcs stated below:
      List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)


#this simple shells adhere to bettyy style wAY OF CODDING :

#this simple shell is being compiled using gcc:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

#this simple shell is tasted if its working in interactive mode by :                                                 
and if  it is in interactive mode it will displa the following :
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$ 

#it is also tasted if it works in non interractive mde by  

and will display the following 
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


# this simple shell tends to  achive ACCEPTING COMMANS BOTH BUILTINS AND NON BUILTINS BRINGIN BACK THE DESIRED RESULT.....and its a success.
