NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O2

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11

LIBFT_PATH = ./LIBFT/
LIBFT_NAME = libft
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INCLUDES = -I/usr/include -I$(MLX_PATH) -I$(LIBFT_PATH) -I.

SRC_PATH = ./
SRC =	so_long.c \
		input_validate.c \
		clean_init.c \
		exit_cleanup.c \
		map_create.c \
		map_validate.c \
		mlx_window.c \
		input_manage.c \
		render_map.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJS = $(SRC:.c=.o)
OBJECTS = $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -lm

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
