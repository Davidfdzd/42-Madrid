SRCS_SERVER = server_bonus.c
SRCS_CLIENT = client_bonus.c check_error.c

INCLUDE = include
LIBFT = libft
OBJDIR_SERVER = objs_server/
OBJDIR_CLIENT = objs_client/

OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJDIR_SERVER)%.o)
OBJS_CLIENT = $(SRCS_CLIENT:%.c=$(OBJDIR_CLIENT)%.o)

CC = cc -I$(INCLUDE) -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SERVER = server
CLIENT = client

all: lib $(SERVER) $(CLIENT)

bonus: lib $(SERVER) $(CLIENT)

lib:
	make -C $(LIBFT)

$(SERVER): $(OBJS_SERVER)
	make -C $(LIBFT)
	$(CC) $(OBJS_SERVER) -L$(LIBFT) -lft -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	make -C $(LIBFT)
	$(CC) $(OBJS_CLIENT) -L$(LIBFT) -lft -o $(CLIENT)

$(OBJDIR_SERVER)%.o: %.c
	mkdir -p $(OBJDIR_SERVER)
	$(CC) -c $< -o $@

$(OBJDIR_CLIENT)%.o: %.c
	mkdir -p $(OBJDIR_CLIENT)
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -rf $(OBJDIR_SERVER) $(OBJDIR_CLIENT)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all lib clean fclean re bonus