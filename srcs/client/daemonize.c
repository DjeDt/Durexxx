#include "client.h"

void    create_daemon_old_style(void)
{
    int i;
    int devnul;
    pid_t pid;

    // step 1
    close(0);
    close(1);
    close(2);
    // check getrlimit / RLIMIT_NOFILE

    // step 2
    // iterate on all signals
    i = 0;
    while (i < _NSIG)
    {
        signal(i, SIG_IGN);
        i++;
    }

    // set 3
    // not sure if it works, needs more debug
    sigset_t set; //sigset_t oldset;
    sigprocmask(SIG_SETMASK, &set, NULL);

    // maybe clean env (step 4)

    // step 5
    // create background process
    pid = fork();
    if (pid < 0)
        exit(-1); // failed
    if (pid > 1) // kill parent
        exit(1);

    // ret is 0 so now we are the child process,

    // step 6
    setsid();

    // step 7
    // start daemon
    pid = fork();
    if (pid < 0)
        exit(-1);
    if (pid > 0)
        exit(1);

    // now in 2nd child aka daemon

    // step 9
    devnul = open("/dev/null", O_WRONLY);
    dup2(0, devnul);
    dup2(1, devnul);
    dup2(2, devnul);

    // step 10
    // set caller process files to 0
    umask(0);

    // step 11
    chdir("/");

    // next steps : useless ?    sleep(60);

    // looks good :
    // > ps -xj | grep "./client"
    // 1   84071   84068   84068 ?             -1 S     1000   0:00 ./client

    return ;
}
