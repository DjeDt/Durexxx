#include "durex.h"

int     main(void)
{

    create_daemon_old_style();

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
