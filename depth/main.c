/*
** main.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 15:04:14 2017 Tamsi Besson
** Last update Tue May  9 16:56:49 2017 Tamsi Besson
*/

#include "depth.h"

char  **open_map(int fd)
{
  char **maze;
  int i;

  i = 0;
  maze = malloc (100 * sizeof(char *));
  while ((maze[i] = get_next_line(fd)))
    i++;
  return (maze);
}

/*void dfs(t_graph *graph, char **maze, int v)
{
  t_node *node;

  while (v < graph->vertices)
  {
    node = graph->adjList[v].node;
    maze[node->pos.y][node->pos.x] = 'o';
    while (node)
    {
      if (node->next != NULL && node->next->visited == 1)
      {
        v = node->next->id;
        node->visited = 0;
        break;
      }
      else
        v = node->id;
      node->visited = 0;
      node = node->next;
    }
    //printf("v = %d\n", v);
  }
  if (node->visited == 1)
    dfs(graph, maze, v);
}*/

void dfs(t_graph *graph, char **maze, int v)
{
  t_node *node;

  node = graph->adjList[v].node;
  //node->visited = 0;
  maze[node->pos.y][node->pos.x] = 'o';
  while (node)
  {
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
  if ((fd = open(my_strcat("../mazes/", av[1]), O_RDONLY)) == -1)
    return (84);
  maze = open_map(fd);
  graph = createGraph(count_vertices(maze));
  fill_graph(maze, graph);
  displayGraph(graph);
  dfs(graph, maze, 0);
  while (maze[i])
    printf("%s\n", maze[i++]);
  return (0);
}
