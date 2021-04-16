/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pirntf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:50:19 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/12 14:04:35 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*replacestars(const char *str, int i, va_list args)
{
	char		*res;
	char		*temp;
	char		*ff;
	int			j;

	j = 0;
	res = ft_strdup("");
	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		temp = (str[i] != '*') ? (char *)(str + i) : ft_itoa(va_arg(args, int));
		ff = res;
		res = ft_strjoin(res, temp);
		free(ff);
		j += (str[i] != '*') ? 1 : ft_strlen(temp);
		if (str[i] == '*')
			free(temp);
		i++;
		res[j] = '\0';
	}
	res[j] = str[i];
	res[j + 1] = '\0';
	return (res);
}

t_flags		read_flags(const char *str, int i, va_list args)
{
	t_flags		flags;
	char		*str_2;

	str_2 = replacestars(str, i, args);
	flags.isnegative = is_signed(str_2, 0);
	flags.number = hasnum(str_2, 0);
	flags.type = gettype(str_2, 0);
	flags.zero = haszero(str_2, 0);
	flags.precision = hasprecision(str_2, 0);
	free(str_2);
	return (flags);
}

void		apply_flags(t_flags flags, va_list args)
{
	if (flags.type == 's')
		prints(flags, args);
	else if (flags.type == 'c' || flags.type == '%')
		print_cp(flags, args, flags.type);
	else if (flags.type == 'i' || flags.type == 'd')
		printd(flags, args);
	else if (flags.type == 'u')
		printu(flags, args);
	else if (flags.type == 'p' || flags.type == 'x' || flags.type == 'X')
		printpx(flags, args, flags.type);
}

int			printf_magic(va_list args, const char *str, int i)
{
	t_flags flags;

	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1, 1);
		return (i);
	}
	flags = read_flags(str, i, args);
	apply_flags(flags, args);
	while (!ft_isalpha(str[i]) && str[i] != '%')
		i++;
	return (i);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i = printf_magic(args, str, ++i);
		else
			ft_putchar_fd(str[i], 1, 1);
		i++;
	}
	va_end(args);
	count = ft_putchar_fd(' ', 1, 2);
	ft_putchar_fd(' ', 1, -1);
	return (count);
}
