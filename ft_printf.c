/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:50:24 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 17:13:48 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(char ch, va_list args)
{
	int	r;

	r = 0;
	if (ch == 'c')
		r += ft_putchar(va_arg(args, int));
	else if (ch == 's')
		r += ft_putstr(va_arg(args, char *));
	else if (ch == 'd')
		r += ft_putnbr(va_arg(args, int));
	else if (ch == 'i')
		r += ft_putnbr(va_arg(args, int));
	else if (ch == 'p')
		r += ft_putptr(va_arg(args, void *));
	else if (ch == 'u')
		r += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (ch == 'x')
		r += ft_puthex(va_arg(args, unsigned int), 0);
	else if (ch == 'X')
		r += ft_puthex(va_arg(args, unsigned int), 1);
	else if (ch == '%')
		r += ft_putchar('%');
	return (r);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		r;

	i = 0;
	r = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			r += ft_handle_format(s[i], args);
		}
		else
			r += ft_putchar(s[i]);
		i++;
	}
	return (r);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	ft_printf("C : %d\n", ft_printf("R : %s\n", argv[1]));
// 	return (0);
// }
