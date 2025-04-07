NAME = philo

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = sources
OBJ_DIR = objs

SRCS = $(addprefix $(SRC_DIR)/, ft_error.c main.c ft_init.c ft_time.c \
				ft_grim_reaper.c output.c parsing.c philosophers.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):	$(OBJS)
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -o $@ $(OBJS)
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "$(GREEN)cleaning...$(RESET)"
		@rm -rf $(OBJ_DIR)
		@echo "$(GREEN)$(NAME) is clean.$(RESET)"

fclean: clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re