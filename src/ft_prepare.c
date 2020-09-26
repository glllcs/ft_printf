/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:12:13 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:14:59 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prepare the convertion in case of %c:
** Creates a string pre whith the character and a '\0'.
** Calls ft_print_all to print the full identifier.
*/

void			ft_prepare_c(t_general *gen, t_ident ident)
{
	int		c;
	char	pre[3];

	c = va_arg(gen->argument, int);
	pre[0] = (c) ? (unsigned char)c : '\\';
	pre[1] = (c) ? '\0' : '0';
	pre[2] = '\0';
	ft_print_all(gen, ident, pre);
}

/*
** Prepare the convertion in case of %s:
** Allocates a string str whith the string to be printed.
** Calls ft_print_all to print the full identifier.
** Frees str
*/

void			ft_prepare_s(t_general *gen, t_ident ident)
{
	char	*str;

	if (!(str = ft_strdup(va_arg(gen->argument, char *))))
		str = ft_strdup("(null)");
	if (ident.precision == 0 && ident.width == 0)
	{
		ft_strfree(&str);
		return ;
	}
	if (ident.precision >= 0 && ident.precision < (int)ft_strlen(str))
		str[ident.precision] = '\0';
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void			ft_prepare_p(t_general *gen, t_ident ident)
{
	size_t	p;
	char	*str;

	p = va_arg(gen->argument, size_t);
	str = ft_get_nbr(p, &ident);
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void			ft_prepare_pct(t_general *gen, t_ident ident)
{
	char	pre[2];

	pre[0] = '%';
	pre[1] = '\0';
	ft_print_all(gen, ident, pre);
}

void			ft_prepare_nbr(t_general *gen, t_ident ident)
{
	long			n;
	unsigned int	un;
	char			*str;

	if (ident.conversion == 'u')
	{
		un = va_arg(gen->argument, long long);
		str = ft_get_nbr(un, &ident);
	}
	else
	{
		n = va_arg(gen->argument, int);
		str = ft_get_nbr(n, &ident);
	}
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}
