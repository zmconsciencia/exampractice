/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h> 
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int findidx(char c)
{
	int i = 0;
	if (c >= 'a' && c <='z')
	{
		i = c - 'a' + 1;
	}
	else if (c >= 'A' && c <='Z')
	{
		i = c - 'A' + 1;
	}
	return (i);
}

void repeat_alpha(char *str)
{
	int i = 0;
	int j;
	while (str[i])
	{
		j = 0;
		while (j < findidx(str[i]))
		{
			write(1, &str[i], 1);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	ft_putchar('\n');
	return (0);
}
