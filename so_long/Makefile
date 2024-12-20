NAME = so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MLX_DIR)
MINILIBX_FLAGS = -lmlx -lX11 -lXext

#VALGRIND = valgrind --leak-check=full --show-leak-kinds=all \
		--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

SRC_DIR = sources
OBJ_DIR = objs
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(addprefix $(SRC_DIR)/, so_long.c ft_check_map.c ft_closed_game.c \
		ft_free.c ft_handle_input.c ft_init_game.c ft_init_map.c ft_render.c \
		ft_strappend.c valid_map.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME) $(EXE)

$(NAME): 	$(LIBFT) $(MLX) $(OBJS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MINILIBX_FLAGS) -L$(MLX_DIR) -o $(NAME)
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
			

$(LIBFT):
				make -C $(LIBFT_DIR) 
				@echo "$(LIBFT): $(GREEN)$(LIBFT) was compiled.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
$(MLX):
				make -C $(MLX_DIR)
				@echo "$(MLX): $(GREEN)$(MLX) was compiled.$(RESET)"

clean:
		@echo
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean
		make -C $(MLX_DIR) clean
		@echo

fclean: clean
		@echo
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean
		make -C $(MLX_DIR) clean
		@echo

re:		fclean all
		@echo

.PHONY: all clean fclean re valgrind exe