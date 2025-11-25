NAME = convert

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;36m
RESET = \033[0m
BOLD = \033[1m

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objs

SRCS = main.cpp ScalarConverter.cpp Converter.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

TOTAL := $(words $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo ""
	@echo "$(BLUE)$(BOLD)⚙  Finalizando compilación...$(RESET)"
	@$(CC) $(CPPFLAGS) -o $@ $(OBJS)
	@echo "$(GREEN)$(BOLD)✔ Build completado con éxito!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@bash -c '\
	total=$(TOTAL); \
	i=0; \
	for src in $(SRCS); do \
	    i=$$((i+1)); \
	    obj=$(OBJ_DIR)/$${src%.cpp}.o; \
	    $(CC) $(CPPFLAGS) -c $$src -o $$obj; \
	    percent=$$(( i * 100 / total )); \
	    filled=$$(( percent / 4 )); \
	    empty=$$(( 25 - filled )); \
	    bar_filled=$$(printf "%0.s█" $$(seq 1 $${filled:-0})); \
	    bar_empty=$$(printf "%0.s░" $$(seq 1 $${empty:-0})); \
	    printf "\r$(GREEN)Compilando %-20s [${BOLD}%s%s${RESET}${GREEN}] %3d%%" "$$src" "$$bar_filled" "$$bar_empty" "$$percent"; \
	done; \
	printf "\n"'

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re