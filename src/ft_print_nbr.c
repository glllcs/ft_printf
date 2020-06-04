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

char	ft_nbr_signal(long long *n, t_ident ident)
{
	if (*n < 0)
	{
		*n *= -1;
		return ('-');
	}
	else if (ident.flags % FLAG_PLUS == 0)
		return ('+');
	else if (ident.flags % FLAG_SPACE == 0)
		return (' ');
	return (0);
}

char		*ft_get_nbr(long long n, t_ident ident)
{
	char	signal;
	char	*temp;
	char	*nbr;
	int		nbr_len;

	signal = ft_nbr_signal(&n, ident);
	temp = ft_itoa(n);
	nbr_len = ft_strlen(temp);
	if (ident.precision > nbr_len)
	{
		nbr = (char *)ft_calloc(ident.precision + 2, sizeof(char));
		ft_memset(nbr, '0', ident.precision + 2);
		if (signal != 0)
		{
			nbr[0] = signal;
			ft_strlcpy(&nbr[ident.precision - nbr_len + 1], temp, nbr_len + 1);
		}
		else
			ft_strlcpy(&nbr[ident.precision - nbr_len], temp, nbr_len + 1);
		free(temp);
		return (nbr);
	}
	nbr_len += (signal != 0) ? 1 : 0;
	if (ident.width > nbr_len)
	{
		nbr = (char *)ft_calloc(ident.width + 1, sizeof(char));
		ft_memset(nbr, '0', ident.width + 1);
		if (signal != 0)
		{
			nbr[0] = signal;
			ft_strlcpy(&nbr[ident.width - nbr_len + 1], temp, nbr_len + 1);
		}
		else
			ft_strlcpy(&nbr[ident.width - nbr_len], temp, nbr_len + 1);
		free(temp);
		return (nbr);
	}
	nbr = (char *)ft_calloc(nbr_len + 1, sizeof(char));
	if (signal != 0)
	{
		nbr[0] = signal;
		ft_strlcpy(&nbr[1], temp, nbr_len + 1);
	}
	else
		ft_strlcpy(nbr, temp, nbr_len + 1);
	free(temp);
	return (nbr);
}

void		ft_printf_d(t_general *gen, t_ident ident)
{
    long long	n;
	char		*nbr;
	int			nbr_len;
	int			cont;

	n = va_arg(gen->argument, int);
	nbr = ft_get_nbr(n, ident);
	nbr_len = ft_strlen(nbr);
	cont = ident.width - nbr_len;
	if (ident.flags % FLAG_MINUS != 0 && cont > 0)
		gen->size += ft_print_space(cont, ident);
	ft_putstr_fd(nbr, 1);
	gen->size += nbr_len;
	if (ident.flags % FLAG_MINUS == 0 && cont > 0)
		gen->size += ft_print_space(cont, ident);
	free(nbr);
}
