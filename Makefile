CC = cc
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE
NAME = minitalk

G_LIBFT_DIR = g_libft
G_LIBFT = $(G_LIBFT_DIR)/libft.a
LIBFT = -L$(G_LIBFT_DIR) -lft

OBJ_DIR = obj

CLIENT_SRC =	src/client.c src/utils.c
SERVER_SRC =	src/server.c src/utils.c

CLIENT_OBJ = $(CLIENT_SRC:%.c=$(OBJ_DIR)/%.o)
SERVER_OBJ = $(SERVER_SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): client server

$(G_LIBFT):
	make -C $(G_LIBFT_DIR)

client: $(CLIENT_OBJ) $(G_LIBFT)
	$(CC) $^ $(LIBFT) -o $@

server: $(SERVER_OBJ) $(G_LIBFT)
	$(CC) $^ $(LIBFT) -o $@

clean:
	make clean -C $(G_LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(G_LIBFT_DIR)
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
