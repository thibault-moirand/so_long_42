NAME = so_long

SRCS = basic/
SRCS_BONUS = bonus/
INCLUDE = ./
MLX_PATH = minilibx-linux/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
MLXFLAGS = -lX11 -lXext

FILES = main.c	\
	create_map.c	\
	create_map02.c	\
	del.c	\
	get_next_line_utils.c	\
	get_next_line.c	\
	inite.c	\
	mouv.c	\
	use.c	\
	use02.c	\
	verif.c

FILES_BONUS = main.c	\
	verif.c	\
	use.c	\
	create_map.c	\
	create_map02.c	\
	del.c	\
	inite.c	\
	mouv.c	\
	get_next_line.c	\
	get_next_line_utils.c	\
	use02.c	\
	ennemie.c	\
	inite_ennemie.c	\
	ft_itoa.c	\
	compter.c	\
	dead_verif.c	\
	use03.c	\
	verif_valid_en.c	\
	mouv_ennemie.c

OBJ = $(addprefix $(SRCS), $(FILES:.c=.o))
OBJ_BONUS = ${addprefix $(SRCS_BONUS), $(FILES_BONUS:.c=.o)}

all: mlx $(NAME)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)

bonus: mlx $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $(NAME) -I$(MLX_PATH) -I$(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	@make clean -sC $(MLX_PATH)

re: fclean all