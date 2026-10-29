/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:07:50 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 16:52:56 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	r;

	r = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[r])
		r += ft_putchar(str[r]);
	return (r);
}
