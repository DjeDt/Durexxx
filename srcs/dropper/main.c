#include "dropper.h"

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
        return (false);
    return(true);
}

/// pack the program inside the client ?
// download from remote source ? -> libcurl /
//      -> scratch (https://man7.org/linux/man-pages/man3/getaddrinfo.3.html)?
// https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux
// https://manpages.debian.org/testing/systemd/daemon.7.en.html
int     main(void)
{
    /*
      STEPS -> Dropper :
      1 - check priv
      2 - privesc
      3 - drop local or remote downlaod
      4 - launch trojan
    */

    // check if suid 0
    //  if (!permission_check())
    //  privesc();
    //  return (-1);

    // if (get_remote_daemon() == false)
    //    get_local_daemon();

    // run dropped binary
    char *arg[] = {NULL};

    if (execv("./durex", arg) == -1)
    {
        ft_putendl("exec failed");
        return (-1);
    }

    //if (execv(BINARY_PATH, arg) == -1)
    //   return (-1);

    return (0);
}
