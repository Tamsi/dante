/*
** main.c for  in /home/tbesson/projet_cpe/dante/generator/src
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Wed Apr 24 15:24:28 2017 Tamsi Besson
** Last update Fri Apr 28 10:58:12 2017 Tamsi Besson
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	*x_malloc(size_t n)
{
  char	*tab;

  tab = malloc(n);
  if (tab == NULL)
    {
      my_putstr("Error with malloc\n");
      exit(EXIT_FAILURE);
    }
  return (tab);
}
