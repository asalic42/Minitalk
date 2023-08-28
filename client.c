/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:19:15 by asalic            #+#    #+#             */
/*   Updated: 2023/06/27 11:16:38 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigclient(int signum)
{
	ft_printf("Signal recu par le serveur\n");
	(void)signum;
}

int	error_cases(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i ++;
	}
	return (1);
}

int	check_argues(int argc)
{
	if (argc < 3)
	{
		ft_printf("Not enough argues\n");
		return (0);
	}
	else if (argc > 3)
	{
		ft_printf("Too much argues argues\n");
		return (0);
	}
	else
		return (1);
}

//Make char to bits
void	make_bits(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		signal(SIGUSR1, handle_sigclient);
		pause();
		c >>= 1;
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	if (!check_argues(argc))
		return (0);
	if (!error_cases(argv[1]))
	{
		ft_printf("Wrong PID\n");
		return (0);
	}
	i = 0;
	pid_server = ft_atoi(argv[1]);
	if (kill(pid_server, 0) < 0 || pid_server == 0)
	{
		ft_printf("Wrong PID\n");
		return (0);
	}
	while (argv[2][i])
	{	
		make_bits(pid_server, argv[2][i]);
		i ++;
	}
	ft_printf("\033[1;35m[Fin d'envoi du message]\n");
	return (0);
}
