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
	else if (ident.flags % F_PLUS == 0)
		return ('+');
	else if (ident.flags % F_SPACE == 0)
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

char		*ft_get_nbr(long long n, t_ident *ident)
{
	char	signal;
	char	*temp;
	char	*nbr;
	int		nbr_len;

	signal = ft_nbr_signal(&n, *ident);
	temp = ft_itoa(n);
	nbr_len = ft_strlen(temp);
	if (n == 0 && ident->precision == 0 && signal == 0)
		nbr = NULL;
	else if (ident->precision >= nbr_len)
		nbr = ft_get_nbr_aux(temp, nbr_len, ident->precision, signal);
	else if (ident->width > nbr_len && ident->flags % F_ZERO == 0 && \
				ident->precision == -1) 
	{
		nbr_len += (signal != 0) ? 1 : 0;
		nbr = ft_get_nbr_aux(temp, nbr_len, ident->width, signal);
	}
	else
	{
		nbr_len += (signal != 0) ? 1 : 0;
		nbr = ft_get_nbr_aux(temp, nbr_len, nbr_len, signal);
	}
	if (ident->flags % F_ZERO == 0)
		ident->flags /= F_ZERO;
	ft_strfree(&temp);
	return (nbr);
}

/*char		*ft_nbr_arg_to_string(t_general *gen, t_ident ident)
{
	long long	n;
	char		signal;

	n = va_arg(gen->argument, int);
	signal = ft_nbr_signal(&n, ident);
	temp = ft_itoa(n);

}*/


void		ft_printf_d(t_general *gen, t_ident ident)
{
    long long	n;
	char		*nbr;

	n = va_arg(gen->argument, int);
	nbr = ft_get_nbr(n, &ident);
	ft_print_all(gen, ident, nbr);
	ft_strfree(&nbr);
}

void		ft_printf_u(t_general *gen, t_ident ident)
{
    long long	n;
	char		*nbr;

	n = va_arg(gen->argument, int);
	nbr = ft_get_nbr(n, &ident);
	ft_print_all(gen, ident, nbr);
	ft_strfree(&nbr);
}
