CC = cc
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE
NAME = minitalk

G_LIBFT_DIR = g_libft
G_LIBFT = $(G_LIBFT_DIR)/libft.a
LIBFT = -L$(G_LIBFT_DIR) -lft

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
SRC =	src/client.c \
		src/server.c \
		src/utils.c

# OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
# SRC_BONUS =	src/client_bonus.c \
# 			src/server_bonus.c \
# 			src/utils.c

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): client server

$(G_LIBFT):
	make -C $(G_LIBFT_DIR)

client: $(OBJ_DIR)/src/client.o $(OBJ_DIR)/src/utils.o $(G_LIBFT)
	$(CC) $^ $(LIBFT) -o $@

server: $(OBJ_DIR)/src/server.o $(OBJ_DIR)/src/utils.o $(G_LIBFT)
	$(CC) $^ $(LIBFT) -o $@

# bonus: client_bonus server_bonus

# client_bonus: $(OBJ_DIR)/src/client_bonus.o $(OBJ_DIR)/src/utils.o
# 	make -C $(G_LIBFT_DIR)
# 	$(CC) $^ $(LIBFT) -o client

# server_bonus: $(OBJ_DIR)/src/server_bonus.o $(OBJ_DIR)/src/utils.o
# 	make -C $(G_LIBFT_DIR)
# 	$(CC) $^ $(LIBFT) -o server

clean:
	make clean -C $(G_LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(G_LIBFT_DIR)
	rm -f client server
#	rm -f client_bonus server_bonus

re: fclean all

.PHONY: all clean fclean re client server #client_bonus server_bonus