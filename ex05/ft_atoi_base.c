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
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
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

int	ft_get_sign(char **str)
{
	int	sign;

	sign = 1;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -sign;
		(*str)++;
	}
	return (sign);
}

int	ft_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	result;
	int	i;

	base_len = ft_base_len(base);
	if (base_len == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = ft_get_sign(&str);
	result = 0;
	while (*str)
	{
		i = ft_index_in_base(*str, base);
		if (i == -1)
			break ;
		result = result * base_len + i;
		str++;
	}
	return (result * sign);
}
