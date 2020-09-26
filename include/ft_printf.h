/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:10:27 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:10:31 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define CONVERSION	"cspdiuxXo%"

# define FLAGS		"-+0 #"
# define DIGITS		"0123456789"

# define F_MINUS	2
# define F_PLUS		3
# define F_ZERO		5
# define F_SPACE	7
# define F_HASH		11

# define B_DEC		"0123456789"
# define B_OCT		"01234567"
# define B_HEX_L	"0123456789abcdef"
# define B_HEX_U	"0123456789ABCDEF"

typedef struct	s_general
{
	char		*input;
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
}				t_ident;

int				ft_printf(const char *phrase, ...);
void			ft_print_ident(t_general *gen, t_ident *ident);
void			ft_init_ident(t_ident *identifier);
void			get_flags(t_general *gen, t_ident *ident);
int				get_sizes(t_general *gen, t_ident *ident);
void			get_limits(t_general *gen, t_ident *ident);
void			get_conversion(t_general *gen, t_ident *ident);
int				ft_print_space(int cont, t_ident ident);
void			ft_prepare_c(t_general *gen, t_ident ident);
void			ft_prepare_s(t_general *gen, t_ident ident);
void			ft_prepare_p(t_general *gen, t_ident ident);
void			ft_prepare_nbr(t_general *gen, t_ident ident);
void			ft_prepare_pct(t_general *gen, t_ident ident);
void			ft_strfree(char **str);
void			ft_print_all(t_general *gen, t_ident ident, char *pre);
char			*ft_sufix(long long n, t_ident ident);
char			*ft_prefix(long long *n, t_ident ident);
char			*ft_fill_zeros(char *pref, char *suf, int len_beg, int len_end);
char			*ft_get_nbr(long long n, t_ident *ident);

#endif
