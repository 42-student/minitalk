/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:35:09 by smargine          #+#    #+#             */
/*   Updated: 2023/06/11 16:50:33 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_access_var(char format, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(long long int n);
int		ft_puthex(unsigned long long int n, char format);

#endif
