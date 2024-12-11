NAME = libft.a
LIB = ar rcs
FLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c ft_strlcpy.c ft_atoi.c \
				 ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strlen.c \
					ft_calloc.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
					ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
					ft_tolower.c ft_toupper.c ft_putstr_fd.c 
SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
INCLUDE = libft.h
all: $(NAME)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS) $(INCLUDE)

bonus: $(OBJS) $(OBJS_BONUS)
		$(LIB) $(NAME) $(OBJS_BONUS) $(OBJS) $(INCLUDE)
%.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -f $(NAME)

re: fclean $(NAME)
rebonus: fclean bonus

.PHONY: bonus all clean fclean re rebonus