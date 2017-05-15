/*
** fill.c for  in /home/tbesson/projet_cpe/dante/breadth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sun May 14 21:40:48 2017 Tamsi Besson
** Last update Sun May 14 21:55:05 2017 Tamsi Besson
*/

#include "breadth.h"

static void fill_positive(char **maze, t_graph *graph, t_pos newPos, t_pos pos)
{
  if (maze[pos.y][pos.x + 1] != '\0')
    if (maze[pos.y][pos.x + 1] == '*')
      {
        newPos = pos;
        newPos.x = pos.x + 1;
        addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                pos.y * my_strlen(maze[pos.y]) + pos.x + 1,
                newPos
                );
      }
  if (maze[pos.y + 1] != NULL)
    if (maze[pos.y + 1][pos.x] == '*')
      {
        newPos = pos;
        newPos.y = pos.y + 1;
        addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                (pos.y + 1) * my_strlen(maze[pos.y]) + pos.x,
                newPos
                );
      }
}

static void fill_negative(char **maze, t_graph *graph, t_pos newPos, t_pos pos)
{
  if (pos.x > 0)
    if (maze[pos.y][pos.x - 1] == '*')
      {
        newPos = pos;
        newPos.x = pos.x - 1;
        addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                pos.y * my_strlen(maze[pos.y]) + pos.x - 1,
                newPos
                );
      }
  if (pos.y > 0)
    if (maze[pos.y - 1][pos.x] == '*')
      {
        newPos = pos;
        newPos.y = pos.y - 1;
        addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                (pos.y - 1) * my_strlen(maze[pos.y]) + pos.x,
                newPos
                );
      }
}

void fill_graph(char **maze, t_graph *graph)
{
  t_pos pos;
  t_pos newPos;

  pos.y = 0;
  while (maze[pos.y])
    {
      pos.x = 0;
      while (maze[pos.y][pos.x])
        {
          if (maze[pos.y][pos.x] == '*')
            {
              fill_positive(maze, graph, newPos, pos);
              fill_negative(maze, graph, newPos, pos);
            }
          pos.x++;
        }
      pos.y++;
    }
}

int previous(t_queue *q)
{
  return (q->head->prev);
}
