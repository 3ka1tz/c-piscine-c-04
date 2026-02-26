#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	n;
	int		i;
	char	buf[12];

	n = nb;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i-- > 0)
		write(1, &buf[i], 1);
}
