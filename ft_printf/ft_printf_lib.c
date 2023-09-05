/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:37:33 by smargine          #+#    #+#             */
/*   Updated: 2023/06/11 16:49:51 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putnbr(n % 10);
	}
	return (count);
}

int	ft_puthex(unsigned long long int n, char format)
{
	int		count;
	char	*str_lo;
	char	*str_up;

	count = 0;
	str_lo = "0123456789abcdef";
	str_up = "0123456789ABCDEF";
	if (n >= 16)
		count = count + ft_puthex(n / 16, format);
	if (format == 'x' || format == 'p')
		count = count + ft_putchar(str_lo[n % 16]);
	else if (format == 'X')
		count = count + ft_putchar(str_up[n % 16]);
	return (count);
}
