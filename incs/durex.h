#ifndef DUREX_H
# define DUREX_H

# include "libft.h"

# include <stdio.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/stat.h>
# include <arpa/inet.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>


// debug purpose
# include <syslog.h>

# define DEFAULT_ADDR "127.0.0.1"
# define DEFAULT_PORT "4242"

# define MAX_QUEUE 5

typedef struct s_info {
    int socket;
    char *port;
    char *ip;
} t_info;

void    create_daemon_old_style(void);
bool    initialize(t_info *info, char *port);

#endif
