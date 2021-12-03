#include "server.h"

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

bool    initialize(t_info *info)
{
    struct addrinfo hints;
    struct addrinfo *base;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    hints.ai_protocol = IPPROTO_TCP;
    if (getaddrinfo(NULL, info->port, &hints, &base) != 0)
    {
        printf("[LOG !] Can't get address with %s.\n", info->port);
        return (false);
    }
    if (create_server(info, base) != true)
        return (false);
    if (listen(info->socket, MAX_QUEUE) < 0)
    {
        printf("[LOG !] Can't listen socket !\n");
        return (false);
    }

    socklen_t len;
    struct sockaddr_in	addr;

    // Accept the data packet from client and verification
    int test = accept(info->socket, (struct sockaddr*)&addr, &len);
    if (test < 0)
    {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
    close(info->socket);
    return (true);
}
