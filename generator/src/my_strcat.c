/*
** my_strcat.c for  in /home/Tamsi/CPool_Day07
** 
** Made by Tamsi Besson
** Login   <Tamsi@epitech.net>
** 
** Started on  Wed Oct 12 11:17:37 2016 Tamsi Besson
** Last update Thu Apr 27 16:30:50 2017 Tamsi Besson
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
  int i;
  int j;
  char *str;

  i = 0;
  j = 0;
  str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 1));
  while (dest[i])
    {
      str[i] = dest[i];
      i++;
    }
  while (src[j])
    {
      str[i] = src[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}
