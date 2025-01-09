CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk

G_LIBFT_DIR = g_libft
LIBFT = -L$(G_LIBFT_DIR) -lft

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
SRC =	src/client.c \
		src/server.c \
		src/utils.c

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): client server

client: $(OBJ)
	make -C $(G_LIBFT_DIR)
	$(CC) $(OBJ_DIR)/src/client.o $(OBJ_DIR)/src/utils.o $(LIBFT) -o client

server: $(OBJ)
	make -C $(G_LIBFT_DIR)
	$(CC) $(OBJ_DIR)/src/server.o $(OBJ_DIR)/src/utils.o $(LIBFT) -o server

clean:
	make clean -C $(G_LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(G_LIBFT_DIR)
	rm -f client server

re: fclean all

.PHONY: all clean fclean re client server