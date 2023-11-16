#include "shell.h"


/**
* _path_check - Function to check and execute the command inserted
*@comm: array sotored commands
*@buffer: buffer from getline
*@envi: enviroment variables
*@ar: argument vector
*@c: number of times runned the prompt
*/

void _path_check(char **comm, char *buffer, char **envi, char **ar, int c)
{
	struct stat fStat;
	int x = 0;
	char **dire;

	dire = store_var(commands[0], envi);
	while (dire[x])
	{
		if (stat(dire[x], &fStat) == 0)
			execve(dire[x], comm, NULL);
		x++;
	}

	error_message(ar, comm[0], c);

	free(buffer);
	free_memory(comm);
	free_memory(dire);
	exit(EXIT_SUCCESS);
}

/**
* g_out - Free the buffer and commands taken from getline
*@buffer: buffer taked from getline
*@comm: command inserted
*Return: Nothing(void)
*/

void g_out(char *buffer, char **comm)
{
	free(buffer);
	free_memory(comm);
	exit(EXIT_SUCCESS);
}

/**
*  free_buf- Free the buffer created
*@buffer: buffer taked from getline
*Return: Nothing(void)
*/

void free_buf(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
* end_env - Function to frees the buffer and commands created in getline
*@buffer: buffer from getline
*@comm: array store commands
*@envi: enviroment variables
*Return: Nothing(void)
*/

void end_env(char *buffer, char **comm, char **envi)
{
	free(buffer);
	free_memory(comm);
	print_envi(envi);
	exit(EXIT_SUCCESS);
}


