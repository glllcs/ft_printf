/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:14:08 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:14:15 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_nbr(long long n, t_ident *ident)
{
	char	signal;
	char	*temp;
	char	*nbr;
	int		nbr_len;

	signal = ft_signal(&n, *ident);
	temp = ft_itoa_case(n, *ident);
	nbr_len = ft_strlen(temp);
	if (n == 0 && ident->precision == 0 && signal == 0)
		nbr = NULL;
	else if (ident->precision >= nbr_len)
		nbr = ft_put_zeros(temp, nbr_len, ident->precision, signal);
	else
	{
		nbr_len += (signal != 0) ? 1 : 0;
		if (ident->width > nbr_len && ident->flags % F_ZERO == 0 &&
				ident->flags % F_MINUS != 0 && ident->precision < 0)
			nbr = ft_put_zeros(temp, nbr_len, ident->width, signal);
		else
			nbr = ft_put_zeros(temp, nbr_len, nbr_len, signal);
	}
	while (ident->flags % F_ZERO == 0)
		ident->flags /= F_ZERO;
	ft_strfree(&temp);
	return (nbr);
}

char		ft_signal(long long *n, t_ident ident)
{
	if (ident.conversion == 'x' || ident.conversion == 'X' ||
		ident.conversion == 'p')
		return (0);
	if (*n < 0)
	{
		*n *= -1;
		return ('-');
	}
	else if (ident.flags % F_PLUS == 0)
		return ('+');
	else if (ident.flags % F_SPACE == 0)
		return (' ');
	return (0);
}

char		*ft_itoa_case(long long n, t_ident ident)
{
	char		*nbr;

	if (ident.conversion == 'd' || ident.conversion == 'i' ||
			ident.conversion == 'u')
		nbr = ft_itoa_base_u(n, B_DEC);
	else if (ident.conversion == 'x')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_L);
	else if (ident.conversion == 'X')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_U);
	else if (ident.conversion == 'p')
		nbr = ft_itoa_base_u(n, B_HEX_L);
	else
		nbr = NULL;
	return (nbr);
}

char		*ft_put_zeros(char *i_nbr, int i_len, int new_len, char sig)
{
	char	*nbr;

	nbr = (char *)ft_calloc(new_len + 2, sizeof(char));
	ft_memset(nbr, '0', new_len + 1);
	if (sig != 0)
	{
		nbr[0] = sig;
		ft_strlcpy(&nbr[new_len - i_len + 1], i_nbr, i_len + 1);
	}
	else
		ft_strlcpy(&nbr[new_len - i_len], i_nbr, i_len + 1);
	return (nbr);
}
