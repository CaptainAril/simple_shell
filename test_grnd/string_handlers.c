#include "shell.h"

/**
 * strcat - concatenates two strings
 * @dest: destination string
 * @src: string to be concatenated
 * Return: return dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;
	i = 0, j =0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[i])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: return 0 if s1 and s2 are equal
 *         else any other numbercd cd
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, val =0;

	while(val == 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break;
		val = s1[i] - s2[i];
		i++;
	}
	return (val);
}

/**
 * word_count - counts the number of words in a string
 * @str: string to be checked
 * Return: returns the number of words.
 */
int word_count(char *str)
{
	int i, count, flag;

	flag = 0;
	count = 0;
	for (i = 0; str[i]; i++)
	{
		if ((str[i] != ' ' && str[i] != '\t') && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (str[i] == ' ' || str[i] == '\t')
			flag = 0;
	}
	return (count);
}
