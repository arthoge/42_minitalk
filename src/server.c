/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:47 by aoger             #+#    #+#             */
/*   Updated: 2025/01/13 17:58:58 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_signal_queue	g_signal_queue = {
	.signals = {0},
	.front = 0,
	.rear = 0
};

static int	ft_enqueue_signal(unsigned char signal)
{
	int	next_rear;

	next_rear = (g_signal_queue.rear + 1) % BUFFER_SIZE;
	if (next_rear == g_signal_queue.front)
		return (-1);
	g_signal_queue.signals[g_signal_queue.rear] = signal;
	g_signal_queue.rear = next_rear;
	return (0);
}

static unsigned char	ft_dequeue_signal(void)
{
	unsigned char	signal;

	signal = g_signal_queue.signals[g_signal_queue.front];
	g_signal_queue.front = (g_signal_queue.front + 1) % BUFFER_SIZE;
	return (signal);
}

static int	ft_is_queue_empty(void)
{
	return (g_signal_queue.front == g_signal_queue.rear);
}

static void	ft_signal_handler(int bit, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				bit_position = 0;
	unsigned char			signal;

	(void)context;
	if (ft_enqueue_signal(bit) == -1)
		ft_exit_error("Signal queue overflow.\n");
	if (!ft_is_queue_empty())
	{
		signal = ft_dequeue_signal();
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
		kill(info->si_pid, SIGUSR1);
	}
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
