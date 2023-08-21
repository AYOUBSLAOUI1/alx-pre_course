#include "simple_shell.h"

char simple_getchar(void)
{
	char j;
	ssize_t to_read;

	to_read = read(STDIN_FILENO, &j, 1);
	(return (to_read == 1) ? j : EOF);
}

ssize_t simple_line(char **line, size_t *len, FILE *stream)
{
	char *buffer = NULL, *new_buffer;
	size_t buffer_size = 0, chars_read = 0;
	char j;

	if (line == NULL || len == NULL || stream == NULL)
		(return -1);

	if (*line == NULL)
	{
		*line = malloc(*len);
		if (*line == NULL)
			(return -1);
	}

	buffer = *line;
	buffer_size = *len;

	while ((j = simple_getchar()) != EOF)
	{
		if (chars_read + 1 >= buffer_size)
		{
			buffer_size += 128;
			new_buffer = simple_realloc(buffer, buffer_size);
			if (new_buffer == NULL)
			{
				free(buffer);
				(return -1);
			}
			buffer = new_buffer;
		}
		buffer[chars_read++] = j;
		if (j == '\n')
			break;
	}

	if (chars_read == 0)
	{
		free(buffer);
		(return -1);
	}

	buffer[chars_read] = '\0';
	*line = buffer;
	*len = buffer_size;

	(return chars_read);
}
