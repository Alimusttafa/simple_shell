#include "shell.h"

/**
* exec_comm - Function to verify and execute every command
*@comm: command get
*@buffer: command in getline
*@envi: enviroment variable
*@ar: argument counter
*@c: number of times that executed
*Return: Nothing(void)
*/

void exec_comm(char **comm, char *buffer, char **envi, char **ar, int c)
{
	struct stat fStat;

	if (comm == NULL)
		free_buf(buffer);
	else if (_strcmp("exit", comm[0]))
		g_out(buffer, comms);
	else if (_strcmp("envi", comm[0]))
		end_env(buffer, comm, envi);
	else if (stat(comm[0], &fStat) == 0)
		execve(comm[0], comm, NULL);
	else
		_path_check(comm, buffer, envi, ar, c);
}

