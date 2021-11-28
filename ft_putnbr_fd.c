/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:45:58 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 07:27:45 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	chec_nbr(int *counter, long *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		ft_putchar_fd('-', 1);
		(*counter)++;
	}
}

int	ft_putnbr_fd(long n, int fd)
{
	int		i;
	int		a;
	long	nbr;
	int		counter;

	counter = 1;
	chec_nbr(&counter, &n);
	i = 1;
	a = 10;
	nbr = n;
	while (n / a != 0)
	{
		n = n / a;
		i = i * 10;
		counter++;
	}
	while (i != 0)
	{
		ft_putchar_fd(nbr / i + '0', fd);
		nbr = nbr % i;
		i = i / 10;
	}
	return (counter);
}
