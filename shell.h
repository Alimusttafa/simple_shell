#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void _path_check(char **comm, char *buffer, char **envi, char **ar, int c);
void g_out(char *buffer, char **comm);
void free_buf(char *buffer);
void end_env(char *buffer, char **comm, char **envi);

char **_point_str(char *s);
unsigned int number_of_command(char *s);
void print_envi(char **envi);
char **store_var(char *f_comm, char **envi);
unsigned int find_num(char *pa);
char *g_env(const char *n, char **envi);
char *_strncpcomm(char *desti, char *sr, char *comm, int n_len, int c_len);

void error_message(char **a, char *f_com, int c);
void fork_fa(void);
void file_cont(char *buffer);
int _puterror(char chr);

void exec_comm(char **comm, char *buffer, char **envi, char **ar, int c);

void free_memory(char **ptr);
void buffer_free(char *buffer, char **c);
void _send(char *buffer, char **c);

void handle_promot(int signal);
void dollar_sign(void);

#endif /*SHELL.H*/
