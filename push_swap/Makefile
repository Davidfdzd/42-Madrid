NAME = push_swap

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(LIBFT_DIR)

SRC_DIR = sources
OBJ_DIR = objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(addprefix $(SRC_DIR)/, algorithms.c checks.c ft_error.c index.c main.c \
				operations1.c operations2.c operations3.c stacks.c utils.c ksort.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

$(LIBFT):
			@echo
			@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIR) clean
		@echo

fclean: clean
		@echo
		@rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean
		@echo "$(NAME): $(GREEN)$(NAME) is clean.$(RESET)"

re:		fclean all
		@echo

.PHONY: all clean fclean re