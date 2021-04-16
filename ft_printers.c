/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 23:53:01 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/14 15:11:07 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints(t_flags flags, va_list args)
{
	int		i;
	int		blanks;
	char	*str;
	int		len;

	i = -1;
	str = va_arg(args, char*);
	str = (str == NULL) ? "(null)" : str;
	len = (flags.precision <= ft_strlen(str)
			&& flags.precision > -1) ? flags.precision : ft_strlen(str);
	blanks = (flags.number >= len) ? flags.number - len : 0;
	while (flags.isnegative == 0 && blanks--)
		ft_putchar_fd(' ', 1, 1);
	while (++i < len)
		ft_putchar_fd(str[i], 1, 1);
	while (flags.isnegative != 0 && blanks--)
		ft_putchar_fd(' ', 1, 1);
}

void	print_cp(t_flags flags, va_list args, char type)
{
	int		blanks;
	char	c;

	blanks = (flags.number >= 1) ? flags.number - 1 : 0;
	c = (type == '%') ? '%' : (char)va_arg(args, int);
	while (flags.isnegative == 0 && blanks--)
		ft_putchar_fd((flags.zero && type != 'c') ? '0' : ' ', 1, 1);
	ft_putchar_fd(c, 1, 1);
	while (flags.isnegative != 0 && blanks--)
		ft_putchar_fd(' ', 1, 1);
}

void	printd(t_flags flags, va_list args)
{
	int num;
	int zeros;
	int blanks;
	int kkk;

	num = va_arg(args, int);
	zeros = (flags.precision <= (taille(num) - (num < 0)))
		? 0 : flags.precision - (taille(num) - (num < 0));
	kkk = taille(num);
	blanks = (flags.number >= taille(num) + zeros)
		? flags.number - (taille(num) + zeros) : 0;
	if (flags.isnegative)
		printd_if(num, zeros, flags, blanks);
	else
		printd_else(num, blanks, flags, zeros);
}

void	printu(t_flags flags, va_list args)
{
	int				i;
	int				blanks;
	unsigned int	num;
	int				zeros;

	i = 0;
	num = va_arg(args, unsigned int);
	zeros = (flags.precision <= taille_u(num))
		? 0 : flags.precision - taille_u(num);
	blanks = (flags.number >= (taille_u(num) + zeros))
		? flags.number - (taille_u(num) + zeros) : 0;
	while (flags.isnegative == 0 && blanks--)
		ft_putchar_fd((flags.zero && flags.precision < 0)
				? '0' : ' ', 1, 1);
	while (zeros-- > 0)
		ft_putchar_fd('0', 1, 1);
	if (flags.isnegative == 0 && !(flags.precision == 0
				&& flags.number == 0 && num == 0))
		i = (num == 0 && flags.precision == 0)
			? ft_putchar_fd(' ', 1, 1) : ft_uputnbr_fd(num, 1);
	if (flags.isnegative)
		i = (num == 0 && flags.precision == 0)
			? ft_putchar_fd(' ', 1, 1) : ft_uputnbr_fd(num, 1);
	while (flags.isnegative && blanks--)
		ft_putchar_fd(' ', 1, 1);
}

void	printpx(t_flags flags, va_list args, char type)
{
	int		blanks;
	char	*str;
	int		len;
	int		zeros;

	str = getstrforpx(args, flags, type);
	len = ft_strlen(str);
	zeros = (flags.precision <= len) ? 0 : (flags.precision - len);
	blanks = (flags.number >= ((int)ft_strlen(str) + zeros))
		? flags.number - (ft_strlen(str) + zeros) : 0;
	while (flags.isnegative == 0 && blanks--)
		ft_putchar_fd((flags.zero && flags.precision < 0) ? '0' : ' ', 1, 1);
	while (zeros-- > 0)
		ft_putchar_fd('0', 1, 1);
	if (flags.isnegative == 0 && !(flags.precision == 0
				&& flags.number == 0 && (len == 1 && str[0] == '0')))
		len = ((len == 1 && str[0] == '0') && flags.precision == 0)
			? ft_putchar_fd(' ', 1, 1) : ft_putstr_fd(str, 1);
	if (flags.isnegative)
		len = ((len == 1 && str[0] == '0') && flags.precision == 0)
			? ft_putchar_fd(' ', 1, 1) : ft_putstr_fd(str, 1);
	while (flags.isnegative && blanks--)
		ft_putchar_fd(' ', 1, 1);
	free(str);
}
