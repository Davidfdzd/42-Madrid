NAME = cub3D

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR) -I$(MLX_DIR)
MINILIBX_FLAGS = -lmlx -lX11 -lXext -lm

SRC_DIR = sources
OBJ_DIR = objs
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

SRCS = $(addprefix $(SRC_DIR)/, main.c) \
			$(addprefix $(SRC_DIR)/input/, input.c) \
			$(addprefix $(SRC_DIR)/render/, render_1.c render_2.c render_3.c) \
			$(addprefix $(SRC_DIR)/player/, player.c) \
			$(addprefix $(SRC_DIR)/init/, init.c) \
			$(addprefix $(SRC_DIR)/parsing/, verify.c parse_color.c parse_file.c parse_map_grid.c normalize_map_grid.c) \
			$(addprefix $(SRC_DIR)/utils/, utils_1.c) \
			$(addprefix $(SRC_DIR)/free/, free.c) \
			$(addprefix $(SRC_DIR)/texture/, texture.c)

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME) $(EXE)

$(NAME): 	$(LIBFT) $(MLX) $(OBJS)
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MINILIBX_FLAGS) -L$(MLX_DIR) -o $(NAME)
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
			

$(LIBFT):
				@make -C $(LIBFT_DIR) 
				@echo "$(LIBFT): $(GREEN)$(LIBFT) was compiled.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
$(MLX):
				@make -C $(MLX_DIR)
				@echo "$(MLX): $(GREEN)$(MLX) was compiled.$(RESET)"

clean:
		@echo "$(GREEN)cleaning...$(RESET)"
		rm -rf $(OBJ_DIR)
		make -C $(LIBFT_DIR) clean
		make -C $(MLX_DIR) clean
		@echo "$(GREEN)$(NAME) is clean.$(RESET)"

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean
		make -C $(MLX_DIR) clean

re:		fclean all

.PHONY: all clean fclean re valgrind exe