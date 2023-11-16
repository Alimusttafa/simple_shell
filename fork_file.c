#include "shell.h"

/**
* error_message - Function to write an error message
*@a: argument vector
*@f_com: first command to print if not found
*@c: number of times executed
*Return: Nothing(void)
*/

void error_message(char **a, char *f_com, int c)
{
	int number_len = 1, cp, mul = 1;

	write(STDERR_FILENO, a[0], _strlen(a[0]));
	write(STDERR_FILENO, ": ", 2);
	cp = c;

	while (cp >= 10)
	{
		cp /= 10;
		mul *= 10;
		number_len++;
	}

	while (number_len > 1)
	{
		if ((c / mul) < 10)
			_puterror((c / mul + '0'));
		else
			_puterror((c / mul) % 10 + '0');
		--number_len;
		mul /= 10;
	}

	_puterror(c % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, f_com, _strlen(f_com));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * fork_fa - function that handles a fork fail
 * Return: Nothing
*/

void fork_fa(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}


/**
* file_cont - function to control the interrupt signal
*@buffer: buffer array created by new line
*Return: Nothing(void)
*/

void file_cont(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}

/**
* _puterror - Prints a char
*@chr: character to write
*Return: int to print
*/

int _puterror(char chr)
{
	return (write(STDERR_FILENO, &chr, 1));
}


