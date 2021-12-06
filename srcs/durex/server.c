#include "durex.h"

bool    create_server(t_info *info, struct addrinfo *base)
{
    struct addrinfo *ptr;

    ptr = base;
    while (ptr != NULL)
    {
        info->socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (info->socket < 0)
            continue ;
        if (bind(info->socket, ptr->ai_addr, ptr->ai_addrlen) == 0)
            break ;
        close(info->socket);
        ptr = ptr->ai_next;
    }
    freeaddrinfo(base);
    if (ptr == NULL)
    {
        printf("[Log !] Can't bind address. abort\n");
        return (false);
    }
    return (true);
}

bool    initialize(t_info *info, char *port)
{
    struct addrinfo hints;
    struct addrinfo *base;

    memset(&hints, 0x0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(NULL, port, &hints, &base) != 0)
    {
        printf("[LOG !] Can't get address with %s.\n", port);
        return (false);
    }
    if (create_server(info, base) != true)
    {
        printf("create server failed\n");
        return (false);
    }

    if (listen(info->socket, MAX_QUEUE) < 0)
    {
        printf("[LOG !] Can't listen socket !\n");
        return (false);
    }
    return (true);
}
