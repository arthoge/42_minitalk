/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:41 by aoger             #+#    #+#             */
/*   Updated: 2025/01/10 16:31:21 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	ft_send_signal(int pid, char *message)
{
	int					bit;
	unsigned char		c;

	while (*message)
	{
		c = (unsigned char)*message;
		bit = 0;
		while (bit < 8)
		{
			if (c & (1 << bit))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			bit++;
		}
		message++;
	}
	bit = 0;
	while (bit < 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_print_error("Usage: ./client <server_pid> <message>\n");
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_print_error("Invalid PID\n");
		return (1);
	}
	message = av[2];
	if (message[0] == '\0')
	{
		ft_print_error("Empty message\n");
		return (1);
	}
	ft_send_signal(server_pid, message);
	return (0);
}
