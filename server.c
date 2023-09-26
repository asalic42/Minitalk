/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:19:35 by asalic            #+#    #+#             */
/*   Updated: 2023/09/26 20:27:00 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *plus)
{
	static char			bits;
	static unsigned int	tour_count;

	(void)plus;
	if (signum == SIGUSR2)
		bits |= 1 << tour_count;
	tour_count ++;
	if (tour_count == 8)
	{
		ft_printf("%c", bits);
		bits = 0;
		tour_count = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid_server;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	pid_server = getpid();
	ft_printf("Bonjour\n");
	ft_printf("\033[1;35m[My PID : %d] \033[0m\n", pid_server);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
