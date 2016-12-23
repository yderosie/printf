
#include "ft_printf.h"

unsigned int	count_c_octal(ull i)
{
	ull j;
	ull k;

	j = 0;
	while (j >= 8)
	{
		k = i;
		i = i / 8;
		k = (k % 8);
		j++;
	}
	j += 2;
	return (j);
}

ull	conv_octal(ull j)
{
	int remainder;
	ll o;
	ll i;

	o = 0;
	i = 1;
	while (j != 0)
	{
		remainder = j % 8;
		j = j / 8;
		o = o + (remainder * i);
		i = i * 10;
	}
	return (o);
}
/*
unsigned int	conv_octal(ull j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_octal(j)));
	while  (j >= 8)
	{
		k = j;
		j = j / 8;
		k = (k % 8);
		s1[i] = k + '0';
		i++;
	}
	s1[i] = j + '0';
	s2 = ft_inverse(s1);
	j = ft_atoi(s2);
	return (j);
}*/