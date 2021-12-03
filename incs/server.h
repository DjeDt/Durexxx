#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "libft.h"

# define DEFAULT_PORT "1337"
# define MAX_QUEUE 10

typedef struct s_info {
    int socket;
    char *port;
    char *ip;
} t_info;

bool    initialize(t_info *info);

#endif
