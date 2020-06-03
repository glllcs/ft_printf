/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 08:45:30 by lambrozi          #+#    #+#             */
/*   Updated: 2020/06/03 08:45:32 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_d(t_general *gen, t_ident ident)
{
    long long	n;
	char		*nbr;
	int			nbr_len;
	int			cont;

	n = va_arg(gen->argument, int);
	nbr = ft_itoa(n);
	nbr_len = ft_strlen(nbr);
	if (ident.flags % FLAG_PLUS == 0 && n >= 0)
	{
		ft_putchar_fd('+', 1);
		nbr_len++;
	}
	/*if (ident.precision >= 0 && ident.precision < str_len)
	{
		str[ident.precision] = '\0';
		str_len = ident.precision;
	}*/
	cont = ident.width - nbr_len;
	if (ident.flags % FLAG_MINUS != 0 && cont > 0)
		gen->size += ft_print_space(cont, ident);
	ft_putstr_fd(nbr, 1);
	gen->size += nbr_len;
	if (ident.flags % FLAG_MINUS == 0 && cont > 0)
		gen->size += ft_print_space(cont, ident);
	free(nbr);
}
