NAME = megaphone

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJ_DIR = objs

SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -o $@ $(OBJS)
	@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) is clean.$(RESET)"

re: fclean all

.PHONY: all clean fclean re