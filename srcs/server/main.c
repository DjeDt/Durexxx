#include "server.h"

#define ERROR_ARG 1

void    error(int err)
{
    if (err == ERROR_ARG)
    {
        printf("Error on provided arguments. Abort\n");
    }
}

int     server(const char *ip, int port)
{
    printf("provided configuration is %s:%i\n", ip, port);
    return (0);
}

int     main(int ac, char **av)
{
  int   port;
  char  *ip;

  port = 0;
  ip = NULL;
  if (ac != 1)
  {
      if (ac == 2)
          ip = av[1];
      else if (ac == 3)
      {
          ip = av[1];
          port = ft_atoi(av[2]);
      }
      else
      {
          error(ERROR_ARG);
          return (-1);
      }
  }
  server(ip, port);
  return (0);
}
