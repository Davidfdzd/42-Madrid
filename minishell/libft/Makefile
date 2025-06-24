NAME = libft.a

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIB = ar rcs
FLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c ft_strlcpy.c ft_atoi.c ft_strcmp.c\
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strlen.c \
				ft_calloc.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
				ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c \
				gnl.c gnl_utils.c ft_printf.c ft_printf_utils.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		@$(LIB) $(NAME) $(OBJS)
		@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

%.o: %.c
		@cc $(FLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME): $(GREEN)$(NAME) is clean.$(RESET)"

re: fclean $(NAME)

.PHONY: all clean fclean re 