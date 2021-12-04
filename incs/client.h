#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"

# include <stdio.h>
# include <stdbool.h>
# include<string.h>
# include <netdb.h>
# include <signal.h>

# include<sys/socket.h>
# include<arpa/inet.h>
# include <sys/types.h>
# include <sys/stat.h>


# define DEFAULT_PORT 80
# define DEFAULT_IP "127.0.0.1"
# define RECV_LEN 2048

# define BINARY "this is the Durex :D"
# define GET_REQUEST "GET /durex HTTP/1.0\r\nHost: www.toto.42\r\n\r\n"

typedef struct  s_data
{
    void        *line;
    int         len;
    struct s_data *next;
} t_data;

// core
bool    get_daemon(void);
bool    download_daemon(int sock, int fd);
void    parse_request(t_data *data, int fd);
int     init_connection(void);

void    create_daemon_old_style(void);

// list
t_data  *data_create(const char *buffer, int len);
void    data_push(t_data **data, t_data *chunk);
void    data_add(t_data **data, const char *buffer, int len);
void    data_free(t_data **data);


#endif
