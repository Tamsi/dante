/*
** node.c for  in /home/tbesson/projet_cpe/dante/breadth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue May  9 17:55:27 2017 Tamsi Besson
** Last update Sun May 14 18:57:10 2017 Tamsi Besson
*/

#include "breadth.h"

int count_vertices(char **maze)
{
  int i;
  int size;

  i = 0;
  size = 0;
  while (maze[i])
    {
      size += my_strlen(maze[i]);
      i++;
    }
  return (size);
}

t_node *createNode(int v)
{
  t_node *newNode;

  newNode = malloc(sizeof(t_node *));
  newNode->id = v;
  return (newNode);
}
