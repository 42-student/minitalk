/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 06:39:35 by smargine          #+#    #+#             */
/*   Updated: 2023/08/04 07:31:54 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	r_msg(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message sent!\n");
}

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
		if (pid < 1000)
			return (ft_printf("Error! Invalid PID!\n"), 1);
		while (av[2][i] != '\0')
			ft_send(pid, av[2][i++]);
		ft_send(pid, '\n');
		ft_send(pid, '\n');
		if (signal(SIGUSR2, r_msg) == SIG_ERR)
			return (ft_printf("ERROR: could not handle SIGUSR2\n"), 1);
		ft_send(pid, '\0');
	}
	else
		return (ft_printf("Error! Try : ./client <PID> <message>\n"), 1);
	return (0);
}
