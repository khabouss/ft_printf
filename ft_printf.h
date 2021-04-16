/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:27:21 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/13 12:44:37 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

typedef	struct	s_printf_flags
{
	int		zero;
	int		number;
	int		isnegative;
	char	type;
	int		precision;
}				t_flags;

t_flags			read_flags(const char *str, int i, va_list args);
int				hasnum(char *str, int i);
char			gettype(char *str, int i);
int				haszero(char *str, int i);
int				is_signed(char *str, int i);
char			*replacestars(const char *str, int i, va_list args);
int				hasprecision(char *str, int i);
void			apply_flags(t_flags flags, va_list args);
void			prints(t_flags flags, va_list args);
void			printd(t_flags flags, va_list args);
void			printu(t_flags flags, va_list args);
void			printpx(t_flags flags, va_list args, char type);
void			print_cp(t_flags flags, va_list args, char type);
int				ft_printf(const char *str, ...);
void			printd_if(int num, int zeros, t_flags flags, int blanks);
void			printd_else(int num, int blanks, t_flags flags, int zeros);
char			*getstrforpx(va_list args, t_flags flags, char type);

#endif
