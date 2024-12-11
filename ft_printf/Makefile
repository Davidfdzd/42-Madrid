NAME = libftprintf.a
LIB = ar rcs
FLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_printf.c ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)
INCLUDE = ft_printf.h
all: $(NAME)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS) $(INCLUDE)

%.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re