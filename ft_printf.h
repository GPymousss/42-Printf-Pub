/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guletill <guletill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:50:42 by guletill          #+#    #+#             */
/*   Updated: 2026/10/29 17:04:25 by guletill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putptr(void *ptr);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_puthex(unsigned int nbr, int upc);

#endif