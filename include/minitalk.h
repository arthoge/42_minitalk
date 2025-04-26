/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:37:45 by aoger             #+#    #+#             */
/*   Updated: 2025/04/26 16:31:24 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

# include "../g_libft/ft_std/libft.h"
# include "../g_libft/ft_printf/ft_printf.h"
# include "../g_libft/get_next_line/get_next_line_bonus.h"

//utils.c
void	ft_print_error(const char *msg);
void	ft_exit_error(const char *msg);

#endif