/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:47 by aoger             #+#    #+#             */
/*   Updated: 2025/04/26 16:36:37 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_signal_handler(int bit, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				bit_position = 0;

	(void)context;
	if (bit == SIGUSR1)
		character |= (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		if (character == '\0')
			write(1, "\n", 1);
		else
			write(1, &character, 1);
		character = 0;
		bit_position = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_print_error("Failed to send ACK to client");
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
