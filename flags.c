
#include "ft_printf.h"

void	flags_present_2(t_conv *conv, char *s1, int i, int j)
{
	j = 0;
	if (s1[i] == 'h' && s1[i + 1] != 'h')
		conv->flags.fh = 1;
	if (s1[i] == 'h' && s1[i + 1] == 'h')
	{
		conv->flags.fhh = 1;
		i +=1;
	}
	if (s1[i] == 'l' && s1[i + 1] != 'l')
		conv->flags.fl= 1;
	if (s1[i] == 'l' && s1[i + 1] == 'l')
	{
		conv->flags.fll = 1;
		i += 1;
	}
	if (s1[i] == 'j')
		conv->flags.j = 1;
	
	if (s1[i] == '.')
	{
		while (ft_isdigit(s1[i + j + 1]))
			s2[j] = s1[i + (j++) + 1];
		conv->flags.precision = ft_atoi(s2);
	}
}

int		flags_present(t_conv *conv, char *s1, int i)
{
	char	*s2;
	int		j;

	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] != 's' && s1[i] != 'S' && s1[i] != 'p' && s1[i] != 'd'
		&& s1[i] != 'D' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'O'
			&& s1[i] != 'u' && s1[i] != 'U' && s1[i] != 'x' && s1[i] != 'X' &&
			s1[i] != 'c' && s1[i] != 'C' && s1[i] != '\0' && s1[i] != '%')
	{
		if (s1[i] == '0')
			conv->flags.zero = 1; 
		if (s1[i] == '#')
			conv->flags.htag = 1;
		if (s1[i] == '+')
			conv->flags.plus = 1;
		if (s1[i] == ' ')
			conv->flags.espace = 1;
		if (s1[i] == 'z')
			conv->flags.z = 1;
		if (s1[i] == '-')
			conv->flags.moins = 1;
		flags_present_2(conv, s1, i, j);
		i++;
	}
	return (i);
}

void	flags_initialization(t_conv *conv)
{
	conv->flags.zero = 0;
	conv->flags.htag = 0;
	conv->flags.espace = 0;
	conv->flags.moins = 0;
	conv->flags.plus = 0;
	conv->flags.precision = 0;
	conv->flags.fhh = 0;
	conv->flags.fh = 0;
	conv->flags.fl = 0;
	conv->flags.fll = 0;
	conv->flags.j = 0;
	conv->flags.z = 0;
}

ll		diff_return(t_conv *conv)
{
	if (conv->flags.fhh == 1)
		return ((char)va_arg(conv->arg.ap, int));
	if (conv->flags.fh == 1)
		return ((short)va_arg(conv->arg.ap, int));
	if (conv->flags.fl == 1)
		return (va_arg(conv->arg.ap, li));
	if (conv->flags.fll == 1)
		return (va_arg(conv->arg.ap, ll));
	if (conv->flags.j == 1)
		return (va_arg(conv->arg.ap, intmax_t);
	if (conv->flags.z == 1)
		return (va_arg(conv->arg.ap, size_t));
}

ull		diff_u_return(t_conv *conv)
{
	if (conv->flags.fhh == 1)
		return ((unsigned char)va_arg(conv->arg.ap, unsigned int));
	if (conv->flags.fh == 1)
		return ((unsigned short)va_arg(conv->arg.ap, unsigned int));
	if (conv->flags.fl == 1)
		return (va_arg(conv->arg.ap, uli));
	if (conv->flags.fll == 1)
		return (va_arg(conv->arg.ap, ull));
	if (conv->flags.j == 1)
		return (va_arg(conv->arg.ap, uintmax_t));
	if (conv->flags.z == 1)
		return (va_arg(conv->arg.ap, ssize_t));
}