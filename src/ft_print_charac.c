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

void			ft_printf_c(t_general *gen, t_ident ident)
{
	int		c;

	c = va_arg(gen->argument, int);
	if (ident.flags % FLAG_MINUS != 0 && ident.width > 0)
		gen->size += ft_print_space((ident.width - 1), ident);
	ft_putchar_fd(c, 1);
	gen->size++;
	if (ident.flags % FLAG_MINUS == 0 && ident.width > 0)
		gen->size += ft_print_space((ident.width - 1), ident);
}

void			ft_printf_s(t_general *gen, t_ident ident)
{
	char	*str;
	int		str_len;
	int		cont;

	if (!(str = ft_strdup(va_arg(gen->argument, char *))))
		str = ft_strdup("(null)");
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
		gen->size += ft_print_space(cont, ident);
	ft_putstr_fd(str, 1);
	gen->size += str_len;
	if (ident.flags % FLAG_MINUS == 0 && cont > 0)
		gen->size += ft_print_space(cont, ident);
	free(str);
}

void			ft_printf_p(t_general *gen, t_ident ident)
{
	size_t	p;
	char	*nbr;
	int		nbr_len;

	p = va_arg(gen->argument, size_t);
	nbr = ft_itoa_base_u(p, BASE_HEX);
	if (ident.precision == 0 && p == 0)
		nbr[ident.precision] = '\0';
	gen->size += (nbr_len = ft_strlen(nbr) + 2);
	if (ident.flags % FLAG_MINUS != 0 && ident.width - nbr_len > 0)
		gen->size += ft_print_space(ident.width - nbr_len, ident);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(nbr, 1);
	if (ident.flags % FLAG_MINUS == 0 && ident.width - nbr_len > 0)
		gen->size += ft_print_space(ident.width - nbr_len, ident);
	free(nbr);
}

void			ft_printf_pct(t_general *gen, t_ident ident)
{
	if (ident.flags % FLAG_MINUS != 0 && ident.width > 0)
		gen->size += ft_print_space((ident.width - 1), ident);
	ft_putchar_fd('%', 1);
	gen->size++;
	if (ident.flags % FLAG_MINUS == 0 && ident.width > 0)
		gen->size += ft_print_space((ident.width - 1), ident);	
}