/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:54:36 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 17:10:13 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int	r;

	r = 0;
	if (nbr > 9)
	{
		r += ft_putnbr_unsigned(nbr / 10);
		r += ft_putchar((nbr % 10) + '0');
	}
	else
		r += ft_putchar(nbr + '0');
	return (r);
}
