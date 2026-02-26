#include <unistd.h>

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;
	int		i;
	char	buf[32];

	base_len = ft_base_len(base);
	if (base_len == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 0;
	if (n == 0)
		buf[i++] = base[0];
	while (n > 0)
	{
		buf[i++] = base[n % base_len];
		n /= base_len;
	}
	while (i-- > 0)
		write(1, &buf[i], 1);
}
