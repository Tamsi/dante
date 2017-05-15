/*
** main.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 15:04:14 2017 Tamsi Besson
** Last update Sun May 14 22:37:22 2017 Tamsi Besson
*/

#include "breadth.h"

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

static t_queue bfs2(t_node *node, t_queue q, int *visited, int prev)
{
  while (node != NULL)
    {
      if (visited[node->id] < -1)
	enqueue(&q, node, prev);
      node = node->next;
    }
  return (q);
}

static int *bfs(t_graph *graph, int v)
{
  t_queue q;
  t_node *node;
  int *visited;
  int prev;
  int i;

  i = 0;
  visited = malloc(graph->vertices * sizeof(int));
  while (i < graph->vertices)
    visited[i++] = -2;
  initQueue(&q);
  enqueue(&q, graph->adjList[v + 1].node, -1);
  visited[v] = -1;
  prev = -1;
  while (!ifEmpty(&q))
    {
      node = front(&q);
      prev = previous(&q);
      dequeue(&q);
      visited[node->id] = prev;
      prev = node->id;
      node = graph->adjList[node->id].node;
      q = bfs2(node, q, visited, prev);
    }
  return (visited);
}

static void disp_path(t_graph *graph, char **maze)
{
  int n;
  int i;
  int *visited;

  visited = bfs(graph, 0);
  n = graph->vertices - 1;
  while (n >= 0)
    {
      maze[n / 10][n % 10] = 'o';
      n = visited[n];
    }
  i = 0;
  while (maze[i])
    {
      printf("%s\n", maze[i++]);
    }
}

int main(int ac, char **av)
{
  int fd;
  char **maze;
  t_graph *graph;

  if (ac <= 1)
    return (84);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (84);
  maze = open_map(fd);
  graph = createGraph(count_vertices(maze));
  fill_graph(maze, graph);
  disp_path(graph, maze);
  return (0);
}
