/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargine <smargine@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 06:25:36 by smargine          #+#    #+#             */
/*   Updated: 2023/08/04 00:47:40 by smargine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	ft_handler(int signo, siginfo_t *info, void *context)
{
	static int	i;
	static int	c;

	(void)context;
	if (signo == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
			{
				ft_printf("Error: could not send SIGUSR2!\n");
				exit(1);
			}
		}
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac == 1)
	{
		ft_printf("\nWELCOME TO THE SERVER {[-_-]}\n\n");
		ft_printf("The PID is: %d\n\n", getpid());
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = ft_handler;
		while (ac == 1)
		{
			if (sigaction(SIGUSR1, &sa, NULL) == -1)
				return (ft_printf("ERROR: could not handle SIGUSR1!\n"), 1);
			if (sigaction(SIGUSR2, &sa, NULL) == -1)
				return (ft_printf("ERROR: could not handle SIGUSR2!\n"), 1);
		}
	}
	else
		return (ft_printf("Error! Try: ./server to run the program!\n"), 1);
	return (0);
}
