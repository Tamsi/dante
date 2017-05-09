/*
** main.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 15:04:14 2017 Tamsi Besson
** Last update Sun May  7 20:32:31 2017 Tamsi Besson
*/

#include "breadth.h"

char  **open_map(int fd)
{
  char **maze;
  int i;

  i = 0;
  maze = malloc (50 * sizeof(char *));
  while ((maze[i] = get_next_line(fd)))
    i++;
  return (maze);
}

void BFS(t_graph *graph, char **maze)
{
  int i;
  int j;
  int *visited;
  int id = 0;

  visited = malloc(count_vertices(maze) * sizeof(t_node));
  i = 0;
  while (i < count_vertices(maze))
  {
    visited[i] = 0;
    i++;
  }
  t_node *node = graph->adjList[0].node;
  while(node != NULL)
  {
    visited[node->id] = 1;
    if (node->next != NULL && !visited[node->next->id])
    {
      node = node->next;
      printf("%d\n", graph->adjList[id].node->id);
      id = graph->adjList[id].node->id;
      if (graph->adjList[id].node->next != NULL)
        id = graph->adjList[id].node->next->id;
    }
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
  BFS(graph, maze);
  while (maze[i])
    printf("%s\n", maze[i++]);
  return (0);
}
