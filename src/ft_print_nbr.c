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

char		*ft_get_nbr_aux(char *i_nbr, int i_len, int new_len, char signal)
{
	char	*nbr;

	nbr = (char *)ft_calloc(new_len + 1, sizeof(char));
	ft_memset(nbr, '0', new_len + 1);
	if (signal != 0)
	{
		nbr[0] = signal;
		ft_strlcpy(&nbr[new_len - i_len + 1], i_nbr, i_len + 1);
	}
	else
		ft_strlcpy(&nbr[new_len - i_len], i_nbr, i_len + 1);
	return (nbr);
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
	if (n == 0 && ident.precision == 0 && signal == 0)
		nbr = NULL;
	else if (ident.precision >= nbr_len)
		nbr = ft_get_nbr_aux(temp, nbr_len, ident.precision, signal);
	else if (ident.width > nbr_len && ident.flags % FLAG_ZERO == 0) 
	{
		nbr_len += (signal != 0) ? 1 : 0;
		nbr = ft_get_nbr_aux(temp, nbr_len, ident.width, signal);
	}
	else
	{
		nbr_len += (signal != 0) ? 1 : 0;
		nbr = ft_get_nbr_aux(temp, nbr_len, nbr_len, signal);
	}
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
