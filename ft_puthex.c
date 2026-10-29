/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:01:55 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 17:08:00 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, int upc)
{
	int		r;
	char	*b;

	r = 0;
	if (upc)
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
	if (nbr > 15)
	{
		r += ft_puthex(nbr / 16, upc);
		r += ft_putchar(b[nbr % 16]);
	}
	else
		r += ft_putchar(b[nbr]);
	return (r);
}
