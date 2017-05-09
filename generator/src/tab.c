/*
** tab.c for  in /home/tbesson/projet_cpe/dante/generator/src
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Mon Apr 24 15:24:28 2017 Tamsi Besson
** Last update Fri Apr 28 11:00:06 2017 Tamsi Besson
*/

#include "my.h"

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	free(tab[i++]);
      free(tab);
    }
}

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void	fd_tab(char **tab, int fd)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      fd_putstr(tab[i], fd);
      fd_putchar('\n', fd);
      i++;
    }
}

int	size_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
      i++;
  return (i);
}
