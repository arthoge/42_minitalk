/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:08:34 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:52:24 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../ft_std/libft.h"

int		ft_printf(const char *format, ...);
int		ft_intlen(int n);
int		ft_uns_intlen(unsigned int n);
void	ft_putnbr_uns_fd(unsigned int n, int fd);
void	ft_puthex_fd(unsigned long n, int fd);
void	ft_puthex_maj_fd(unsigned long n, int fd);
int		ft_hexlen(unsigned long n);
int		ft_handle_specifiers(char specifier, va_list args);
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_handle_int(va_list args);
int		ft_handle_uns_int(va_list args);
int		ft_handle_hex(va_list args);
int		ft_handle_hex_maj(va_list args);
int		ft_handle_percent(void);

#endif