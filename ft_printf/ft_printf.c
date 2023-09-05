/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:37:33 by smargine          #+#    #+#             */
/*   Updated: 2023/06/11 16:47:01 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			res = res + ft_access_var(*(++format), args);
		else
			res = res + ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (res);
}

int	ft_access_var(char format, va_list args)
{
	unsigned long long int	ptr;

	ptr = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, unsigned long long int);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		write(1, "0x", 2);
		return (ft_puthex(ptr, format) + 2);
	}
	else
		return (ft_putchar(format));
}
