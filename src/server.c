/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:05:06 by smargine          #+#    #+#             */
/*   Updated: 2023/08/04 00:40:09 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handler(int signal)
{
	static int	i;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Error! Try: ./server\n");
		return (1);
	}
	ft_printf("\nWELCOME TO THE SERVER {[-_-]}\n\n");
	ft_printf("The PID is: %d\n\n", getpid());
	while (ac == 1)
	{
		if (signal(SIGUSR1, ft_handler) == SIG_ERR)
		{
			ft_printf("ERROR: could not handle SIGUSR1!\n");
			return (1);
		}
		if (signal(SIGUSR2, ft_handler) == SIG_ERR)
		{
			ft_printf("ERROR: could not handle SIGUSR2!\n");
			return (1);
		}
	}
	return (0);
}
