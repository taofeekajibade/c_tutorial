#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/* MACROS */

#define BUFFER_SIZE 64
#define DELIM " \t\r\n\a"
/* PROTOTYPES */

int main(void);
int handle_cd(char **path); /*int handle_cd(char **argv); */
int handle_exit(void);
/*int handle_help(char **argv); */
void display_prompt(void);
int builtin_select(void);
int execute_cmd(char **argv);
void loop_shell(void);
char *read_line(void);
char **split_token(char *userinput);
int fork_process(char **argv);
void handle_sigint(int sig __attribute__ ((unused)));
void print_env(char **env);

#endif
