/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:41 by aoger             #+#    #+#             */
/*   Updated: 2025/04/26 16:34:37 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static volatile int	g_ack_received = 0;

static void	ft_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	ft_send_char(int pid, unsigned char c)
{
	int	i;
	int	res;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if (c & (1 << i))
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res == -1)
			ft_exit_error("Invalid server PID or server not running\n");
		while (!g_ack_received)
			usleep(50);
		i++;
	}
}

static void	ft_send_signal(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		ft_send_char(pid, message[i]);
		i++;
	}
	ft_send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac != 3)
		return (ft_print_error("Usage: ./client <server_pid> <message>\n"), 1);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (ft_print_error("Invalid PID\n"), 1);
	message = av[2];
	if (message[0] == '\0')
		return (ft_print_error("Empty message\n"), 1);
	signal(SIGUSR1, ft_ack_handler);
	ft_send_signal(server_pid, message);
	return (0);
}
