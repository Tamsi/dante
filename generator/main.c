/*
** main.c for solver in /home/tbesson/projet_cpe/dante/generator
** 
** Made by Tamsi Besson
** Login   <tamsi.besson@epitech.eu>
** 
** Started on  Mon Apr 24 09:48:25 2017 Tamsi Besson
** Last update Mon May 15 15:19:58 2017 Tamsi Besson
*/

#include "my.h"

int     perfect_mod(char **av)
{
  int   fd;
  char **tab;

  if ((fd = open(my_strcat("../mazes/", av[3]),
                 O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
                 | S_IRGRP | S_IWGRP | S_IWUSR)) != -1)
    {
      tab = set_maze(atoi(av[1]), atoi(av[2]));
      tab = draw_perfect(tab, atoi(av[1]), atoi(av[2]));
      fd_tab(tab, fd);
      return (0);
    }
  else
    {
      my_putstr("Erreur with open\n");
      return (84);
    }
}

int imperfect_mod(char **av)
{
  int fd;
  char **tab;

  if ((fd = open(my_strcat("../mazes/", av[3]),
                 O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
                 | S_IRGRP | S_IWGRP | S_IWUSR)) != -1)
    {
      tab = set_maze(atoi(av[1]), atoi(av[2]));
      tab = draw_imperfect(tab, atoi(av[1]), atoi(av[2]));
      fd_tab(tab, fd);
      return (0);
    }
  else
    {
      my_putstr("Erreur with open\n");
      return (84);
    }
}

int     main(int ac, char **av)
{

  if (ac < 4)
    {
      my_putstr("Usage: ./binary columns line file_name perfect(1)\n");
      return (84);
    }
  if (ac == 5 && atoi(av[4]) == 1)
    if (perfect_mod(av) != 0)
      return (84);
  if (ac == 4)
    if (imperfect_mod(av) != 0)
      return (84);
  return (0);
}
