/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:29:48 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 06:40:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> 
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int	check_func(va_list ptr, char n)
{
	if (n == 's')
		return (ft_putstr_fd(va_arg(ptr, char *), 1));
	else if ((n == 'd' || n == 'i'))
		return (ft_putnbr_fd((long)va_arg(ptr, int), 1));
	else if (n == 'p')
		return (ft_print_memory(va_arg(ptr, char *), 1));
	else if (n == 'x')
		return (convert_hex_long_ptr(va_arg(ptr, unsigned int), 0));
	else if (n == 'u')
		return (ft_putnbr_fd(va_arg(ptr, unsigned int), 1));
	else if (n == 'X')
		return (convert_hex_long_ptr(va_arg(ptr, unsigned int), 32));
	else if (n == '%')
		write(1, "%%", 1);
	else if (n == 'c')
		ft_putchar_fd(va_arg(ptr, int), 1);
	return (1);
}

int	ft_printf(const char *n, ...)
{
	int		index;	
	int		cuml;
	va_list	ptr;

	va_start(ptr, n);
	index = 0;
	cuml = 0;
	while (n[index] != '\0')
	{
		if (n[index] == '%')
		{
			cuml += check_func(ptr, n[index + 1]);
			index++;
		}
		else
		{
			write(1, &n[index], 1);
			cuml += 1;
		}
		index++;
	}
	va_end(ptr);
	return (cuml);
}
