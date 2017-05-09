/*
** perfect.c for solver in /home/tbesson/projet_cpe/dante/generator
** 
** Made by Tamsi Besson
** Login   <tamsi.besson@epitech.eu>
** 
** Started on  Mon Apr 24 09:48:25 2017 Tamsi Besson
** Last update Fri Apr 28 10:59:51 2017 Tamsi Besson
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**set_maze(int x, int y)
{
  int	i;
  int	j;
  char	**tab;

  i = 0;
  tab = malloc(sizeof(char *) * (y + 1));
  while (i < y)
    {
      j = 0;
      tab[i] = malloc(sizeof(char) * (x + 1));
      while (j < x)
        tab[i][j++] = '*';
      tab[i][j] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char	**draw_perfect(char **tab, int x, int y)
{
  int	i;
  int	j;

  i = 1;
  while (i < y)
    {
      j = 0;
      while (j < x)
        tab[i][j++] = 'x';
      if (i + 1 == y)
        tab[i][x - 1] = '*';
      else
        tab[i][rand() % x] = '*';
      if (i + 1 == y)
	i++;
      else
	i = i + 2;
    }
  return (tab);
}

char  **draw_imperfect(char **tab, int x, int y)
{
  int i;
  int j;

  i = 1;
  while (i < y)
    {
      j = 0;
      while (j < x)
        tab[i][j++] = 'x';
      if (i + 1 == y)
        tab[i][x - 1] = '*';
      else
      {
        tab[i][rand() % x] = '*';
        if (x >= 3)
          tab[i][rand() % x] = '*';
      }
      if (i + 1 == y)
  i++;
      else
  i += 2;
    }
  return (tab);
}