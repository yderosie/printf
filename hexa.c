
#include "ft_printf.h"

char	*conv_hexa_p_X_h(void *j)
{
	char			*s1;
	int				i;
	unsigned int	*m;
	char			*s2;
	unsigned int	l;
	unsigned int	k;

	m = (unsigned int*)j;
	l = m[1];
	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(l)));
	while  (l >= 16)
	{
		k = l;
		l = l / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(l);
	s2 = ft_inverse(s1);
	free(s1);
	return (s2);
}

char	*conv_hexa_X(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(j)));
	while  (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa_X(k);
		i++;
	}
	s1[i] = if_forest_hexa_X(j);
	s2 = ft_inverse(s1);
	return (s2);
}

char	*conv_hexa(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(j)));
	while  (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(j);
	s2 = ft_inverse(s1);
	return (s2);
}

unsigned int	count_c_hexa(unsigned int i)
{
	unsigned int j;
	unsigned int k;

	j = 0;
	while (j >= 16)
	{
		k = i;
		i = i / 16;
		k = (k % 16);
		j++;
	}
	j += 2;
	return (j);
}