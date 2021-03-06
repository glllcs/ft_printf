/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:22:03 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:23:12 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_all(t_general *gen, t_ident ident, char *pre)
{
	int		cont;
	int		str_len;
	int		i;

	i = -1;
	str_len = ft_strlen(pre);
	cont = ident.width - ((ident.conversion == 'c') ? 1 : str_len);
	if (ident.flags % F_MINUS != 0 && ident.width > 0)
		gen->size += ft_print_space(cont, ident);
	while (++i < str_len)
	{
		if (ident.conversion == 'c' && str_len == 2)
		{
			ft_putchar_fd('\0', 1);
			str_len = 1;
		}
		else
			ft_putchar_fd(*(pre + i), 1);
	}
	gen->size += str_len;
	if (ident.flags % F_MINUS == 0 && ident.width > 0)
		gen->size += ft_print_space(cont, ident);
}
