/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:33:43 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 16:46:03 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long n)
{
	int		r;
	char	*b;

	r = 0;
	b = "0123456789abcdef";
	if (n > 15)
	{
		r += ft_puthex_long(n / 16);
		r += ft_putchar(b[n % 16]);
	}
	else
		r += ft_putchar(b[n]);
	return (r);
}

int	ft_putptr(void *ptr)
{
	int				r;
	unsigned long	n;

	r = 0;
	n = (unsigned long)ptr;
	if (n == 0)
		return (ft_putstr("(nil)"));
	r += ft_putstr("0x");
	r += ft_puthex_long(n);
	return (r);
}
