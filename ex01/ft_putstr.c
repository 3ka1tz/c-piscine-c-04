#include <stddef.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	write(1, str, count);
}
