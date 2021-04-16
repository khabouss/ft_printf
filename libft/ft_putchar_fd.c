/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:49:20 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/13 11:26:10 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(char c, int fd, int mode)
{
	static int count;

	if (mode == 1)
	{
		write(fd, &c, 1);
		count++;
	}
	if (mode == -1)
		count = 0;
	return (count);
}
