NAME = Form

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objs

SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking...$(RESET)"
	@$(CC) $(CPPFLAGS) -o $@ $(OBJS)
	@echo "$(NAME): $(GREEN)Build complete.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re