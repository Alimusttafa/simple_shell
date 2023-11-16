#include "shell.h"


/**
 * _point_str - create a double pointer array that point to each string
 * @s: command from the terminal
 * Return: array of pointers that are commands to interpret or execute
*/
char **_point_str(char *s)
{
	char *tok, **hold;
	unsigned int l;
	int x = 0;

	s[_strlen(s) - 1] = '\0';
	l = number_of_command(s);
	if (l == 0)
		return (NULL);
	hold = malloc((sizeof(char *) * (l + 1)));
	if (hold == NULL)
		return (NULL);
	tok = strtok(s, " ");
	while (tok != NULL)
	{
		hold[x] = malloc(_strlen(tok) + 1);
		if (hold[x] == NULL)
		{
			free_memory(hold);
			return (NULL);
		}
		_strncpy(hold[x], tok, _strlen(tok) + 1);
		tok = strtok(NULL, " ");
		x++;
	}
	hold[x] = NULL;
	return (hold);
}


/**
 * number_of_command - find the number of commands in a string
 * @s: string that have the commands
 * Return: number of commands
*/
unsigned int number_of_command(char *s)
{
	unsigned int x = 0, f = 0, c = 0;

	while (s[x] != '\0')
	{
		if (s[x] != ' ')
			f = 1;
		if ((f && s[x + 1] == ' ')
			|| (f && s[x + 1] == '\0'))
		{
			++c;
			f = 0;
		}
		x++;
	}
	return (c);
}

