/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:50:24 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 17:27:29 by guletill         ###   ########.fr       */
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
	va_end(args);
	return (r);
}

/*
#include <stdio.h>
#include <limits.h>
 
static void	ft_ret(int ft, int pf)
{
	printf("ret ft : %d | ret pf : %d\n\n", ft, pf);
	fflush(stdout);
}
 
static void	ft_test_cs(void)
{
	int		r;
	char	*null_str;
 
	null_str = NULL;
	r = ft_printf("ft : [%c] [%c] [%c]\n", 'a', '0', ' ');
	ft_ret(r, printf("pf : [%c] [%c] [%c]\n", 'a', '0', ' '));
	r = ft_printf("ft : [%c]\n", 0);
	ft_ret(r, printf("pf : [%c]\n", 0));
	r = ft_printf("ft : [%s] [%s]\n", "Hello 42", "");
	ft_ret(r, printf("pf : [%s] [%s]\n", "Hello 42", ""));
	r = ft_printf("ft : [%s]\n", null_str);
	ft_ret(r, printf("pf : [%s]\n", null_str));
	r = ft_printf("ft : [%%] [100%%] [%%%%]\n");
	ft_ret(r, printf("pf : [%%] [100%%] [%%%%]\n"));
	r = ft_printf("ft : sans conversion\n");
	ft_ret(r, printf("pf : sans conversion\n"));
}
 
static void	ft_test_nbr(void)
{
	int	r;
 
	r = ft_printf("ft : [%d] [%d] [%d]\n", 0, 42, -42);
	ft_ret(r, printf("pf : [%d] [%d] [%d]\n", 0, 42, -42));
	r = ft_printf("ft : [%d] [%d]\n", INT_MAX, INT_MIN);
	ft_ret(r, printf("pf : [%d] [%d]\n", INT_MAX, INT_MIN));
	r = ft_printf("ft : [%i] [%i] [%i]\n", 0, INT_MAX, INT_MIN);
	ft_ret(r, printf("pf : [%i] [%i] [%i]\n", 0, INT_MAX, INT_MIN));
	r = ft_printf("ft : [%u] [%u] [%u]\n", 0, 42, UINT_MAX);
	ft_ret(r, printf("pf : [%u] [%u] [%u]\n", 0, 42, UINT_MAX));
	r = ft_printf("ft : [%u] [%u]\n", -1, INT_MIN);
	ft_ret(r, printf("pf : [%u] [%u]\n", -1, INT_MIN));
}
 
static void	ft_test_hex(void)
{
	int	r;
	int	x;
 
	x = 42;
	r = ft_printf("ft : [%x] [%x] [%x]\n", 0, 255, -1);
	ft_ret(r, printf("pf : [%x] [%x] [%x]\n", 0, 255, -1));
	r = ft_printf("ft : [%X] [%X] [%X]\n", 0, 255, -1);
	ft_ret(r, printf("pf : [%X] [%X] [%X]\n", 0, 255, -1));
	r = ft_printf("ft : [%x] [%X]\n", INT_MIN, UINT_MAX);
	ft_ret(r, printf("pf : [%x] [%X]\n", INT_MIN, UINT_MAX));
	r = ft_printf("ft : [%p]\n", (void *)&x);
	ft_ret(r, printf("pf : [%p]\n", (void *)&x));
	r = ft_printf("ft : [%p] [%p]\n", NULL, (void *)1);
	ft_ret(r, printf("pf : [%p] [%p]\n", NULL, (void *)1));
	r = ft_printf("ft : [%p] [%p]\n", (void *)LONG_MIN, (void *)ULONG_MAX);
	ft_ret(r, printf("pf : [%p] [%p]\n", (void *)LONG_MIN, (void *)ULONG_MAX));
}
 
int	main(void)
{
	int	r;
 
	ft_test_cs();
	ft_test_nbr();
	ft_test_hex();
	r = ft_printf("ft : %c|%s|%d|%i|%u|%x|%X|%%\n", 'A', "42", -1, 1, 7, 26, 26);
	ft_ret(r, printf("pf : %c|%s|%d|%i|%u|%x|%X|%%\n",
		'A', "42", -1, 1, 7, 26, 26));
	return (0);
}
*/
