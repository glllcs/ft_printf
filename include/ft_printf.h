/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:45:32 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/23 19:02:40 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define CONVERSION	"cspdiuxX%"

# define FLAGS		"-+0 #"
# define DIGITS		"0123456789"

# define FLAG_MINUS	2
# define FLAG_PLUS	3
# define FLAG_ZERO	5
# define FLAG_SPACE	7
# define FLAG_HASH	11

# define BASE_HEX	"0123456789abcdef"

typedef struct	s_general
{
	const char	*input;
	char		*output;
	va_list		argument;
	int			size;
	int			posit;
}				t_general;

typedef struct	s_ident
{
	int		flags;
	int		width;
	int		precision;
	char	conversion;
	char	*argument;
	int		error;
}				t_ident;

int				ft_printf(const char *phrase, ...);
void			ft_init_ident(t_ident *identifier);
void			get_flags(t_general *gen, t_ident *ident);
int				get_sizes(t_general *gen);
void			get_limits(t_general *gen, t_ident *ident);
void			get_conversion(t_general *gen, t_ident *ident);
void			ft_printf_c(t_general *gen, t_ident ident);
void			ft_printf_s(t_general *gen, t_ident ident);
void			ft_printf_p(t_general *gen, t_ident ident);

#endif
