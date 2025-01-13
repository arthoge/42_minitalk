# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoger <aoger@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 13:56:31 by aoger             #+#    #+#              #
#    Updated: 2024/12/10 14:05:51 by aoger            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj

SRC =	src/get_next_line_bonus.c \
		src/get_next_line_utils_bonus.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

re: clean all

.PHONY: all clean re