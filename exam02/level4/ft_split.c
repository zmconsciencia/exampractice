/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>
#include <stddef.h> // For NULL || (void *)0 || 0

char	**ft_split(char *str)
{
	int		idx;
	int		row;
	int		colum;
	char	**split;

	idx = 0;
	row = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256)))
		return (NULL);
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
		idx++;
	while (str[idx])
	{
		colum = 0;
		if (!(split[row] = (char *)malloc(sizeof(char) * 4092)))
			return (NULL);
		while (str[idx] != ' ' && str[idx] != '\t' && str[idx] != '\n')
			split[row][colum++] = str[idx++];
		while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
			idx++;
		split[row][colum] = '\0';
		row++;
	}
	split[row] = NULL;
	return (split);
}

#include <stdio.h>

int	main(void)
{
	int		idx;
	char	**tab;

	idx = 0;
	tab = ft_split("Goncalo fecha isso sff");
	while (idx < 7)
	{
		printf("String %d : %s\n", idx, tab[idx]);
		idx++;
	}
	return (0);
}