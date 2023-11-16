#include "shell.h"


/**
* print_envi - Function to print all enviroment variables
*@envi: enviroment variables for the user
*Return: Nothing(void)
*/

void print_envi(char **envi)
{
	unsigned int x = 0, len;

	while (envi[x])
	{
		len = _strlen(envi[x]);
		write(STDOUT_FILENO, envi[x], len);
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}


/**
* store_var - Function that create a double pointer array, where stores
*@f_comm: first command inserted in the prompt
*@envi: enviroment variables
*Return: enviroment
*/

char **store_var(char *f_comm, char **envi)
{
	char **dire, *p_envi, *d;
	unsigned int len, x = 0;
	int dire_len, comm_len;

	p_envi = g_env("PATH", envi);
	len = find_num(p_envi);
	dire = malloc(sizeof(char *) * (len + 1));
	if (dire == NULL)
		return (NULL);

	d = strtok(p_envi, ":");

	while (d != NULL)
	{
		dire_len = _strlen(d);
		comm_len = _strlen(f_comm);
		dire[x] = malloc(sizeof(char *) *
		(dire_len + comm_len + 2));
		if (dire[x] == NULL)
		{
			free_memory(dire);//
			return (NULL);
		}
			_strncpcomm(dire[x], d, f_comm,
			dire_len, comm_len);
			x++;
		d = strtok(NULL, ":");
	}

		dire[x] = NULL;

	return (dire);
}

/**
* find_num - Function to find the total number of directories
*@pa: path string
*Return: number of directories in the path
*/
unsigned int find_num(char *pa)
{
	unsigned int x = 0, f = 0, number_dir = 0;

	while (pa[x])
	{
		if (pa[x] != ':')
			f = 1;

		if ((f && pa[x + 1] == ':') || (f && pa[x + 1] == '\0'))
		{
			number_dir++;
			f= 0;
		}
		x++;
		}

		return (number_dir);
}

/**
* g_env - Function to get the enviroment variable
*@n: n of the enviroment variable
*@envi: enviroment variables
*Return: the value associated with the variable
*/

char *g_env(const char *n, char **envi)
{
	char *envi_val, *cp_n;
	unsigned int x = 0, len;

	len =  _strlen_const(n);

	cp_n = malloc(sizeof(char) * len + 1);
	if (cp_n == NULL)
		return (NULL);

	_strncpyconst(cp_n, n, len);

	envi_val = strtok(envi[x], "=");
	while (envi[x])
	{
		if (_strcmp(envi_val, cp_n))
			{																														envi_val = strtok(NULL,"\n");
			free(cp_n);
			return (envi_val);
		}
		x++;
		envi_val = strtok(envi[x], "=");
	}
	free(cp_n);
	return (NULL);
}

/**
* _strncpcomm - Function that copies the path and append a / and command
*@desti: destination to save
*@sr: source
*@comm: command to append
*@n_len: length of destination
*@c_len: length of command
*Return: addres of dest
*/

char *_strncpcomm(char *desti, char *sr, char *comm, int n_len, int c_len)
{
	int x, y;

	for (x = 0; x < n_len && sr[x] != '\0'; x++)
		desti[x] = sr[x];
	desti[x] = '/';
	x++;

	for (y = 0; y < c_len && comm[y] != '\0'; y++, x++)
		desti[x] = comm[y];
	desti[x] = '\0';
	return (desti);
}



