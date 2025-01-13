# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoger <aoger@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:56:16 by aoger             #+#    #+#              #
#    Updated: 2024/12/10 14:59:44 by aoger            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

FTSTD_DIR = ft_std
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

all: $(NAME)

$(NAME):
	make -C $(FTSTD_DIR)
	make -C $(PRINTF_DIR)
	make -C $(GNL_DIR)
	ar rcs $(NAME) $(FTSTD_DIR)/obj/*/*.o $(PRINTF_DIR)/obj/*/*.o $(GNL_DIR)/obj/*/*.o

clean:
	make clean -C $(FTSTD_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
