/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:47:07 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/08 17:47:08 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef long int				t_li;
typedef unsigned long int		t_uli;
typedef long long int			t_ll;
typedef unsigned long long int	t_ull;

typedef struct					s_arg
{
	va_list		ap;
	va_list		save;
}								t_arg;

typedef struct					s_flags
{
	int		htag;
	int		zero;
	int		espace;
	int		moins;
	int		plus;
	int		p;
	int		point;
	int		lg;
	int		fhh;
	int		fh;
	int		fl;
	int		fll;
	int		j;
	int		z;
	int		error;
}								t_flags;

typedef struct					s_conv
{
	char			*s;
	wchar_t			*ss;
	t_ll			d;
	char			dhh;
	t_li			dd;
	char			c;
	wchar_t			cc;
	char			*o;
	char			*oo;
	void			*p;
	t_ull			x;
	t_ull			xx;
	t_ull			u;
	t_uli			uu;
	t_arg			arg;
	t_flags			flags;
}								t_conv;

#endif
