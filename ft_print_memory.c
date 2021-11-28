/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:46:15 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 07:38:20 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include "ft_printf.h"

void	print_hexa(int b, int address)
{
	if (b < 0)
		b = b * -1;
	if (b > 9)
		ft_putchar_fd((b + 87 - address), 1);
	else
		ft_putchar_fd(b + '0', 1);
}

int	reverse_tab(int i, int cuml, int address, int *h)
{
	if (i >= 15)
	{
		cuml += 1;
		write(1, "0", 1);
	}
	while (i++ < 15)
	{
		if (address == 32)
			print_hexa(h[i], address);
		else
			print_hexa(h[i], 0);
		cuml++;
	}
	return (cuml);
}

int	convert_hex_long_ptr(size_t a, int address)
{
	int	i;
	int	h[16];
	int	cuml;

	i = 15;
	cuml = 0;
	while (i >= 0)
	{
		h[i] = a % 16;
		a = a / 16;
		i--;
	}
	while (h[i] == 0)
		i++;
	if (address == 1)
	{
		write(1, "0x", 2);
		cuml += 2;
	}
	i--;
	return (reverse_tab(i, cuml, address, h));
}

int	ft_print_memory(void *addr, int address)
{
	char	*ptr;
	long	e;

	ptr = addr;
	e = (long) addr;
	return (convert_hex_long_ptr(e, address));
}
