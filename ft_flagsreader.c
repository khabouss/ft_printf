/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:26:30 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/12 15:16:38 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hasnum(char *str, int i)
{
	int p;

	i = (str[i] == '0');
	p = 0;
	while (!ft_isalpha(str[p]) && str[p] != '%' && str[p] != '.')
		p++;
	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		if (ft_isdigit(str[i]) && i < p)
			return (ft_atoi(str + i));
		i++;
	}
	return (0);
}

char	gettype(char *str, int i)
{
	while (!ft_isalpha(str[i]) && str[i] != '%')
		i++;
	return (str[i]);
}

int		haszero(char *str, int i)
{
	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		if (str[i] == '0' && !ft_isdigit(str[i - 1]) && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		is_signed(char *str, int i)
{
	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		if (str[i] == '-' && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		hasprecision(char *str, int i)
{
	int res;

	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		if (str[i] == '.')
		{
			res = ((ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
				? ft_atoi(str + i + 1) : 0;
			return (res);
		}
		i++;
	}
	return (-1);
}
