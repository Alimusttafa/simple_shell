#include "shell.h"
/**
 * free_memory - frees all the memory including a double pointer
 * @ptr: pointer to free
 * Return: Nothing
*/

void free_memory(char **ptr)
{
	unsigned int x = 0;

	if (ptr == NULL)
		return;

	while (ptr[x])
	{
		free(ptr[x]); 
		x++;
	}

	if (ptr[x] == NULL)
		free(ptr[x]);
	free(ptr);
}

/**
 * buffer_free - free the buffer and the commands
 * @buffer: buffer in getline
 * @c: double pointer that store all the commands inserted
 * Return: Nothing
*/

void buffer_free(char *buffer, char **c)
{
	free(buffer);
	free_memory(c);
}

/**
* _send - Function to send free when the child is not created
*@buffer: buffer created by getline
*@c: array of commands
*Return: Nothing(void)
*/

void _send(char *buffer, char **c)
{
	if (c == NULL)
		buffer_free(buffer, c);
	else if (_strcmp("exit", c[0]))
		g_out(buffer, c);
	else
		buffer_free(buffer, c);
}

