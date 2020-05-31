/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 01:50:36 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/31 01:50:38 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_space(int cont)
{
	int		i;

	i = -1;
	while (++i < cont)
		ft_putchar_fd(' ', 1);
	return (cont > 0) ? (cont) : (0);
}

void			ft_printf_c(t_general *gen, t_ident ident)
{
	int		c;

	c = va_arg(gen->argument, int);
	if (ident.flags % FLAG_MINUS != 0 && ident.width > 0)
		gen->size += ft_print_space(ident.width - 1);
	ft_putchar_fd(c, 1);
	gen->size++;
	if (ident.flags % FLAG_MINUS == 0 && ident.width > 0)
		gen->size += ft_print_space(ident.width - 1);
}

void			ft_printf_s(t_general *gen, t_ident ident)
{
	char	*str;
	int		str_len;
	int		cont;

	str = ft_strdup(va_arg(gen->argument, char *));
	if (ident.precision == 0 && ident.width == 0)
	{
		free(str);
		return ;
	}
	str_len = ft_strlen(str);
	if (ident.precision >= 0 && ident.precision < str_len)
	{
		str[ident.precision] = '\0';
		str_len = ident.precision;
	}
	cont = ident.width - str_len;
	if (ident.flags % FLAG_MINUS != 0 && cont > 0)
		gen->size += ft_print_space(cont);
	ft_putstr_fd(str, 1);
	gen->size += str_len;
	if (ident.flags % FLAG_MINUS == 0 && cont > 0)
		gen->size += ft_print_space(cont);
	free(str);
}
