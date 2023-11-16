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

unsigned int number_of_command(char *s);
char **_point_str(char *s);

free_memory(char *ptr);
buffer_free(char *buffer, char **c);
_send(char *buffer, char **c);

char *_strncpy(char *destination, char *s, int l);
char *_strncpyconst(char *destination, const char *s, int l);
unsigned int _strlen_const(const char *s);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);

void handle_promot(int signal);
dollar_sign(void);

void free_buf(char *buffer);
void g_out(char *buffer, char **comm);
void end_env(char *buffer, char **comm, char **envi);
void _path_check(char **comm, char *buffer, char **envi, char **ar, int c);

unsigned int find_num(char *pa);
char **store_var(char *f_comm, char **envi);
char *g_env(const char *n, char **envi);
char *_strncpcomm(char *desti, char *sr, char *comm, int n_len, int c_len);

void print_envi(char **envi);
void fork_fa(void);
void error_message(char **a, char *f_com, int c);
int _puterror(char chr);
void file_cont(char *buffer);
void exec_comm(char **comm, char *buffer, char **envi, char **ar, int c);





#endif /*SHELL.H*/

