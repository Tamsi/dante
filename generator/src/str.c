/*
** str.c for  in /home/tbesson/projet_cpe/dante/generator/src
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Mon Apr 24 15:24:28 2017 Tamsi Besson
** Last update Fri Apr 28 11:00:19 2017 Tamsi Besson
*/

#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void    my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	fd_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

void	fd_putstr(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}
