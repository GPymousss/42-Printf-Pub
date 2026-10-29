/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:13:31 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 16:32:42 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	r;

	r = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		r += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		r += ft_putnbr(nbr / 10);
		r += ft_putnbr(nbr % 10);
	}
	else
		r += ft_putchar(nbr + '0');
	return (r);
}
