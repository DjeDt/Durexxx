#include "server.h"

int     server(t_info info)
{
    if (info.port == 0)
    {
        ft_putendl("Provided port is not ok.");
        return (-1);
    }
    ft_putendl("test32");
    initialize(&info);
    return (0);
}

int     main(int ac, char **av)
{
    t_info info;

    info.port = DEFAULT_PORT;
    info.ip = NULL;
    if (ac != 1)
    {
        if (ac == 2)
            info.ip = av[1];
        else if (ac == 3)
        {
            info.ip = av[1];
            info.port = av[2];
        }
        else
        {
            ft_putendl("usage : blablabla");
            return (-1);
        }
    }
    bool t = server(info);
    printf("bool = %d\n", t);
    return (0);
}
