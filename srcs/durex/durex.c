#include "durex.h"

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

void get_path(char *ptr)
{
    char *pid;

    ft_strcat(ptr, "/proc/");
    pid = ft_itoa(getpid());
    ft_strcat(ptr, pid);
    free(pid);
    ft_strcat(ptr, "/fd/");
}

/// pack the program inside the client ?
// download from remote source ? -> libcurl /
//      -> scratch (https://man7.org/linux/man-pages/man3/getaddrinfo.3.html)?
// https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux
// https://manpages.debian.org/testing/systemd/daemon.7.en.html
int     main(void)
{
    // check if suid 0
    //  if (!permission_check())
    //  privesc();
    //  return (-1);

    // check if it's already runnin on the system

    //    get_daemon();
    create_daemon_old_style();

    // debug
    syslog (LOG_NOTICE, "Daemon started");
    // persistance

    closelog();
    // evasion

    // remote access : open ports and listen on 4242

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
