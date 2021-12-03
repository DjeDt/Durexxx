SERVER	= server
CLIENT	= client

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra $(includes)
EFLAGS	= -g3 -fsanitize=address

incdir	= ./incs/
srcdir	= ./srcs/
objdir	= .obj

# subdir
libdir		= libft/
clientdir	= client/
serverdir	= server/

server_src = \
	$(serverdir)/main.c \
	$(serverdir)/server.c

client_src = \
	$(clientdir)/main.c \
	$(clientdir)/download.c \
	$(clientdir)/list.c

includes = -I $(incdir) -I $(libdir)/includes -L $(libdir) -lft

server_obj = $(addprefix $(srcdir), $(server_src:%.c=%.o))
client_obj = $(addprefix $(srcdir), $(client_src:%.c=%.o))

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(SERVER): $(server_obj)
	$(CC) $(EFLAGS) -o $@ $^ $(includes)

$(CLIENT): $(client_obj)
	$(CC) $(EFLAGS) -o $@ $^ $(includes)

clean:
	$(RM) $(server_obj) $(client_obj)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
