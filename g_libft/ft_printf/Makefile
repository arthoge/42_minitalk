# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoger <aoger@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:56:04 by aoger             #+#    #+#              #
#    Updated: 2024/12/10 14:43:06 by aoger            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj

SRC =	utils/ft_puthex_fd.c \
		utils/ft_puthex_maj_fd.c \
		utils/ft_hexlen.c \
		utils/ft_intlen.c \
		utils/ft_putnbr_uns_fd.c \
		utils/ft_uns_intlen.c \
		src/ft_printf.c \
		src/ft_handle_specifiers.c \
		src/ft_handle_char.c \
		src/ft_handle_string.c \
		src/ft_handle_pointer.c \
		src/ft_handle_int.c \
		src/ft_handle_uns_int.c \
		src/ft_handle_hex.c \
		src/ft_handle_hex_maj.c \
		src/ft_handle_percent.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean  re