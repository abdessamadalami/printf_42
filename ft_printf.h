/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:48:08 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/28 07:44:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdlib.h>
# include<unistd.h>

int		ft_printf(const char *n, ...);
int		convert_hex_long_ptr(size_t a, int address);
int		ft_print_memory(void *addr, int address);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long n, int f);
int		ft_putstr_fd(char *c, int fd);

#endif
