#include "simple_shell.h"

int simple_putchar(char c)
{
	write(1, &c, 1);
	(return 0);
}

char *simple_strcat(char *dest, char *src)
{

	int c, i;
	for (c = 0; dest[c] != '\0'; c++)

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[c] = src[i];
		c++;
	}

	dest[c] = '\0';
	(return dest);
}

char *simple_strcpy(char *dest, char *src)
{

	int c;
	for (c = 0; src[c] != '\0'; c++)
	{
		dest[c] = src[c];
	}

	dest[c] = '\0';
	(return dest);
}

int simple_strcmp(char *s1, char *s2)
{

	int c;
	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{

		if (s1[c] != s2[c])
		{
			(return s1[c] - s2[c]);
		}
	}

	(return 0);
}

int simple_strlen(char *s)
{

	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	(return len);
}
