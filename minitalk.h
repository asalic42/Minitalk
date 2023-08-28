/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalic <asalic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:09:00 by asalic            #+#    #+#             */
/*   Updated: 2023/06/27 10:27:41 by asalic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libftprintf/libftprintf.h"
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

//Client part
int		error_cases(char *str);
int		check_argues(int argc);

void	make_bits(int pid, char c);
void	handle_sigclient(int signum);

//Server part
void	signal_handler(int signum, siginfo_t *info, void *plus);

//Utils functions
int		ft_atoi(const char *str);

#endif