/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:50:00 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/14 14:33:17 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse(char *str, int j, char type)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (17 + 2 * (type == 'p')));
	res[0] = (type == 'p') ? (i++ + 48) : 0;
	res[1] = (type == 'p') ? (i++ + 119) : 0;
	while (j >= 0)
		res[i++] = str[j--];
	res[i] = '\0';
	return (res);
}

char	*ft_hexaddress_fd(unsigned long n, char type)
{
	char			hexadecimal[17];
	unsigned long	remainder;
	int				j;

	j = 0;
	if (n == 0)
		return ((type == 'p') ? ft_strdup("0x0") : ft_strdup("0"));
	while (n != 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = ((type == 'X') ? 55 : 87) + remainder;
		n = n / 16;
	}
	hexadecimal[j--] = '\0';
	return (reverse(hexadecimal, j, type));
}
