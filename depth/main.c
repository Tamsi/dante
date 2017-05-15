/*
** main.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 15:04:14 2017 Tamsi Besson
** Last update Mon May 15 15:42:50 2017 Tamsi Besson
*/

#include "depth.h"

char  **open_map(int fd)
{
  char **maze;
  int i;

  i = 0;
  maze = malloc (1000 * sizeof(char *));
  while ((maze[i] = get_next_line(fd)))
    i++;
  return (maze);
}

void dfs(t_graph *graph, char **maze, int v)
{
  t_node *node;

  node = graph->adjList[v].node;
  while (node)
  {
    maze[node->pos.y][node->pos.x] = 'o';
    if (node->visited == 1)
    {
      node->visited = 0;
      dfs(graph, maze, node->id);
    }
    node = node->next;
  }
}

int main(int ac, char **av)
{
  int fd;
  int i;
  char **maze;
  t_graph *graph;

  i = 0;
  if (ac <= 1)
    return (84);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  maze = open_map(fd);
  graph = createGraph(count_vertices(maze));
  fill_graph(maze, graph);
  dfs(graph, maze, 0);
  while (maze[i])
    printf("%s\n", maze[i++]);
  return (0);
}
