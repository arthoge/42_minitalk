/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:47 by aoger             #+#    #+#             */
/*   Updated: 2025/01/10 16:54:33 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// for specifif features of POSIX norm such as SA_SIGINFO
#define _POSIX_C_SOURCE 200809L
#include "../include/minitalk.h"

static void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	character = 0;
	static int	bit_position = 0;

	(void)context;
	if (sig == SIGUSR2)
		character |= (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		if (character == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			write(1, &character, 1);
			kill(info->si_pid, SIGUSR1);
		}
		character = 0;
		bit_position = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
