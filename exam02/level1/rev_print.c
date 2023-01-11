/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>


char *rev(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	while(i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		rev(av[1]);
	}
	write(1, "\n", 1);
}