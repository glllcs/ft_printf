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
	char	*prefix;
	char	*sufix;
	char	*nbr;
	int		nbr_len;

	prefix = ft_prefix(&n, *ident);
	sufix = ft_sufix(n, *ident);
	nbr_len = ft_strlen(sufix);
	if ((n == 0 && ident->precision == 0) || ident->precision >= nbr_len)
		nbr = ft_fill_zeros(prefix, sufix, nbr_len, ident->precision);
	else
	{
		nbr_len += ft_strlen(prefix);
		if (ident->width > nbr_len && ident->flags % F_ZERO == 0 &&
				ident->flags % F_MINUS != 0 && ident->precision < 0)
			nbr = ft_fill_zeros(prefix, sufix, nbr_len, ident->width);
		else
			nbr = ft_fill_zeros(prefix, sufix, nbr_len, nbr_len);
	}
	while (ident->flags % F_ZERO == 0)
		ident->flags /= F_ZERO;
	ft_strfree(&prefix);
	ft_strfree(&sufix);
	return (nbr);
}

char		*ft_prefix(long long *n, t_ident ident)
{
	if ((ident.conversion == 'x' && (ident.flags % F_HASH == 0 && *n != 0)) ||
		ident.conversion == 'p')
		return (ft_strdup("0x"));
	else if (ident.conversion == 'X' && (ident.flags % F_HASH == 0 && *n != 0))
		return (ft_strdup("0X"));
	else if (ident.conversion == 'o' && (ident.flags % F_HASH == 0 && *n != 0))
		return (ft_strdup("0"));
	else if (ident.conversion == 'x' || ident.conversion == 'X' ||
		ident.conversion == 'o')
		return (NULL);
	else if (*n < 0)
	{
		*n *= -1;
		return (ft_strdup("-"));
	}
	else if (ident.flags % F_PLUS == 0)
		return (ft_strdup("+"));
	else if (ident.flags % F_SPACE == 0)
		return (ft_strdup(" "));
	return (NULL);
}

char		*ft_sufix(long long n, t_ident ident)
{
	char		*nbr;

	if (n == 0 && ident.precision >= 0)
		nbr = ft_strdup("");
	else if (ident.conversion == 'p')
		nbr = ft_itoa_base_u(n, B_HEX_L);
	else if (ident.conversion == 'd' || ident.conversion == 'i' ||
			ident.conversion == 'u')
		nbr = ft_itoa_base_u(n, B_DEC);
	else if (ident.conversion == 'x')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_L);
	else if (ident.conversion == 'X')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_U);
	else if (ident.conversion == 'o')
		nbr = ft_itoa_base_u(n, B_OCT);
	else
		nbr = NULL;
	return (nbr);
}

char		*ft_fill_zeros(char *pref, char *suf, int len_beg, int len_end)
{
	char	*str;
	int		pref_size;

	pref_size = ft_strlen(pref);
	str = (char *)ft_calloc(len_end + pref_size + 1, sizeof(char));
	ft_memset(str, '0', len_end + pref_size);
	if (pref_size > 0)
	{
		ft_strlcpy(&str[0], pref, pref_size + 1);
		str[pref_size] = '0';
	}
	ft_strlcpy(&str[len_end - len_beg + pref_size], suf, len_beg + 1);
	return (str);
}
