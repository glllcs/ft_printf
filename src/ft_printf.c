/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 08:58:49 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/22 09:53:10 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_printf(const char *phrase)
{
	int	i;

	i = 0;
	while (i != '%' && phrase[i])
	{
		ft_putchar(phrase[i]);
		i++;
	}
	return (i);
}
