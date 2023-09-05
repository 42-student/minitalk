/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:49:01 by smargine          #+#    #+#             */
/*   Updated: 2023/08/04 07:13:03 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error: could not send SIGUSR1!\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error: could not send SIGUSR2!\n");
				exit(1);
			}
		}
		usleep(300);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 5000)
			return (ft_printf("Error! Invalid PID!\n"), 1);
		while (av[2][i] != '\0')
		{
			ft_send(pid, av[2][i]);
			i++;
		}
		ft_send(pid, '\n');
		ft_send(pid, '\n');
	}
	else
	{
		ft_printf("Error! Try: ./client <PID> <message>\n");
		return (1);
	}
	return (0);
}
