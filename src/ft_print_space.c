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

int		ft_print_space(int cont, t_ident ident)
{
	int		i;
	char	c;

	i = -1;
	if (ident.flags % FLAG_ZERO == 0 && ident.flags % FLAG_MINUS != 0)
		c = '0';
	else
		c = ' ';
	while (++i < cont)
		ft_putchar_fd(c, 1);
	return (cont > 0) ? (cont) : (0);
}
