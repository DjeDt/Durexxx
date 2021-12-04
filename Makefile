SERVER	= server
DUREX	= durex
DROPPER	= dropper

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra $(includes)
EFLAGS	= -g3 -fsanitize=address

incdir	= ./incs/
srcdir	= ./srcs/
objdir	= .obj

# subdir
libdir		= libft/
durexdir	= durex/
dropperdir	= dropper/
serverdir	= server/

server_src = \
	$(serverdir)/main.c \
	$(serverdir)/server.c

durex_src = \
	$(durexdir)/main.c \
	$(durexdir)/daemonize.c

dropper_src = \
	$(dropperdir)/main.c \
	$(dropperdir)/download.c \
	$(dropperdir)/list.c

includes = -I $(incdir) -I $(libdir)/includes -L $(libdir) -lft

server_obj	= $(addprefix $(srcdir), $(server_src:%.c=%.o))
durex_obj	= $(addprefix $(srcdir), $(durex_src:%.c=%.o))
dropper_obj	= $(addprefix $(srcdir), $(dropper_src:%.c=%.o))

.PHONY: all clean fclean re

all: lib $(SERVER) $(DUREX) $(DROPPER)

lib:
	@make -C libft

$(SERVER): $(server_obj)
	$(CC) $(EFLAGS) -o $@ $^ $(includes)

$(DUREX): $(durex_obj)
	$(CC) $(EFLAGS) -o $@ $^ $(includes)

$(DROPPER): $(dropper_obj)
	$(CC) $(EFLAGS) -o $@ $^ $(includes)

clean:
	$(RM) $(server_obj) $(durex_obj) $(dropper_obj)

fclean: clean
	$(RM) $(SERVER) $(DUREX) $(DROPPER)

re: fclean all
