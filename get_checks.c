#include "simple_shell.h"

void simple_env_check(char **array)
{
	if (simple_strlen(array[0]) == simple_strlen("env") && simple_strcmp(array[0], "env") == 0)
	{

		int i, k;
		for (i = 0; simple_environ[i] != NULL; i++)
		{
			for (k = 0; simple_environ[i][k] != '\0'; k++)
				simple_putchar(simple_environ[i][k]);
			simple_putchar('\n');
		}
	}
}

int simple_clear_check(char **array)
{
	if (simple_strlen(array[0]) == simple_strlen("clear") && simple_strcmp(array[0], "clear") == 0)
	{
		system("clear");
		(return 0);
	}
	(return 1);
}

void simple_exit_check(char **array, char *line, int exit_stat)

{
	if (simple_strlen(array[0]) == simple_strlen("exit") && simple_strcmp(array[0], "exit") == 0)
	{
		int tmp;
		if (array[1] != NULL)
		{
			tmp = atoi(array[1]);
			simple_free_2D(array);
			free(line);
			exit(tmp);
		} else if (exit_stat == -1)
		{
			simple_free_2D(array);
			free(line);
			exit(0);
		}
		simple_free_2D(array);
		free(line);
		exit(exit_stat);
	}
}

int simple_spaces_tabs_check(char *line)
{
	int c = 0;
	while (line[c] != '\0')
	{
		if (line[c] == ' ' || line[c] == '\t')
			c++;
		else
			break;
	}
	(return (c == simple_strlen(line) - 1) ? 0 : 1);
}
