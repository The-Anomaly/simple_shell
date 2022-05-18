# Simple Shell
This project involves writing a simple UNIX command interpreter. 

#Description
The simple shell reads commands from either a file or standard input and executes them.

# How to run the simple shell
The shell will be initiate by compiling all the .c files in the repository and running the resulting executable.

## To compile:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## To run:
The shell can be used in both interactive and non-interactive mode.

### Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c etc...
($)
($) exit
$
```

### Non-intercative mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c etc...
$
$ cat main.c
{prints out the content of the main.c file to the standard output}
$
$ cat shell.c | ./hsh
{prints out the content of the shell.c file to the standard output}
$
```
