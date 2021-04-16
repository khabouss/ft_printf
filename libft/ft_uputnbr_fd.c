/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:48:38 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/13 11:26:46 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uputnbr_fd(unsigned int newvar, int fd)
{
	if (newvar <= 9)
	{
		ft_putchar_fd(newvar + 48, fd, 1);
	}
	if (newvar > 9)
	{
		ft_uputnbr_fd(newvar / 10, fd);
		ft_putchar_fd(newvar % 10 + 48, fd, 1);
	}
	return (1);
}
