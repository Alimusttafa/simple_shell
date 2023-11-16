#include "shell.h"

/**
* handle_promot - handles signals and write the prompt
*@signal: signal to handle
*Return: Nothing (void)
*/
void handle_promot(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
* dollar_sign - Function to print the dollar sign
*Return: Nothing(void)
*/

void dollar_sign(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
* main - principal function to run the shell
*@argc: argument count
*@argv: argument vector
*@enviroment: enviroment variables
*Return: 0 to exit, 1 if any failures happen
*/

int main(int argc, char **argv, char **enviroment)
{
	char *buffer, **comm;
	size_t l;
	ssize_t chr;
	pid_t p;
	int status, c;
	(void)argc;
	buffer = NULL, l = 0, c = 0;
	dollar_sign();
	while ((chr = getline(&buffer, &l, stdin)))
	{
		signal(SIGINT, INThandler);
		if (chr == EOF)
			file_cont(buffer);
		c++;
		comm = _point_str(buffer);
		p = fork();
		if (p == -1)
			fork_fa();
		if (p == 0)
			exec_comm(comm, buffer, enviroment, argv, c);
		else
		{
			wait(&status);
			_send(buffer, comm);
		}
		l = 0, buffer = NULL;
		dollar_sign();
	}
	if (chr == -1)
		return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
}

