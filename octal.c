
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
//	printf("%lu\n", j);
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
//	printf("%lu\n", o);
	return (o);
}