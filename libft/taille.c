/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:09:38 by tkhabous          #+#    #+#             */
/*   Updated: 2019/12/13 11:27:15 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	taille(int nb)
{
	int size;
	int is_negative;

	if (nb == -2147483648)
		return (11);
	size = 0;
	is_negative = (nb < 0);
	nb = (is_negative) ? nb * -1 : nb;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1 + is_negative);
}

int	taille_u(unsigned int nb)
{
	int size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}
