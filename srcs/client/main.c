#include "client.h"

void    privilege_escalation(void)
{
    // todo
    return ;
}

bool    permission_check()
{
    int uid = getuid();
    // int euid = geteuid();
    // int gid = getgid();

    if (uid != 0)
    {
        privilege_escalation();
        return (false);
    }
    return(true);
}

// pack the program inside the client ?
// download from remote source ? -> libcurl /
//      -> scratch (https://man7.org/linux/man-pages/man3/getaddrinfo.3.html)?
// https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux
int     main(void)
{
    // check if suid 0
    if (!permission_check())
        return (-1);

    get_daemon();

    return (0);
}
