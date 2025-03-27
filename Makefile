NAME = Cub3d

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lX11 -lXext -lm -g

SRC = $(wildcard */*.c) $(wildcard *.c)

OBJ = $(SRC:.c=.o)

MLX = includes/minilibx-linux

LIBFT = includes/libft

all: $(OBJ)

	$(CC) $(OBJ) -I$(LIBFT) -I$(MLX) -L$(MLX) -L$(LIBFT) $(LIBFT)/libft.a $(MLX)/libmlx_Linux.a $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re