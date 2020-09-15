/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:16:55 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:16:56 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_space(int cont, t_ident ident)
{
	int		i;
	char	c;

	i = -1;
	if (ident.flags % F_ZERO == 0 && ident.flags % F_MINUS != 0)
		c = '0';
	else
		c = ' ';
	while (++i < cont)
		ft_putchar_fd(c, 1);
	return (cont > 0) ? (cont) : (0);
}
