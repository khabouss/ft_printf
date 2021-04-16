/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhelp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:53:16 by tkhabous          #+#    #+#             */
/*   Updated: 2020/02/19 10:56:33 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printd_if(int num, int zeros, t_flags flags, int blanks)
{
	int apply;

	apply = (num < 0 && num != -2147483648) ? ft_putchar_fd('-', 1, 1) : 0;
	while (zeros-- > 0)
		ft_putchar_fd('0', 1, 1);
	if (!(flags.precision == 0 && num == 0))
		apply = (num < 0 && num != -2147483648)
			? ft_putnbr_fd(num * -1, 1) : ft_putnbr_fd(num, 1);
	else
		ft_putchar_fd(' ', 1, 1 - 3 * (flags.number == 0));
	while (blanks-- > 0)
		ft_putchar_fd(' ', 1, 1);
}

void	printd_else(int num, int blanks, t_flags flags, int zeros)
{
	int apply;

	apply = ((num < 0 && num != -2147483648) && (!blanks || (flags.zero &&
					flags.precision < 0))) ? ft_putchar_fd('-', 1, 1) : 0;
	while (blanks-- > 0)
		ft_putchar_fd((flags.zero
					&& flags.precision < 0) ? '0' : ' ', 1, 1);
	apply = ((num < 0 && num != -2147483648)
			&& apply == 0) ? ft_putchar_fd('-', 1, 1) : 0;
	while (zeros-- > 0)
		ft_putchar_fd('0', 1, 1);
	if (!(flags.precision == 0 && num == 0))
		apply = (num < 0 && num != -2147483648)
			? ft_putnbr_fd(num * -1, 1) : ft_putnbr_fd(num, 1);
	else
		ft_putchar_fd((flags.precision < 0) ? '0' : ' ', 1, 1
				- 3 * (flags.number == 0 && flags.precision >= 0));
}

char	*getstrforpx(va_list args, t_flags flags, char type)
{
	char			*str;
	unsigned long	a;

	a = (type == 'p') ?
		va_arg(args, unsigned long) : va_arg(args, unsigned int);
	str = ft_hexaddress_fd(a, type);
	str = (ft_strncmp(str, "0x0", 3) == 0
			&& flags.precision == 0) ? ft_strdup("0x") : str;
	return (str);
}
