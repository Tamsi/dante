/*
** main.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 15:04:14 2017 Tamsi Besson
** Last update Fri May 12 11:17:40 2017 Tamsi Besson
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

/*void BFS(t_graph *graph, char **maze)
{
  int i;
  int j;
  int *visited;
  int id = 0;

  visited = malloc(count_vertices(maze) * sizeof(t_node));
  i = 0;
  while (i < graph->vertices)
  {
    visited[i] = 0;
    i++;
  }
  t_node *node = graph->adjList[0].node;
  while (node != NULL)
  {
    visited[node->id] = 1;
    while (node->next != NULL)
    {
      visited[node->id] = 1;
      printf("%d\n", node->id);
      
    }
    node = node->next;
    // if (node->next != NULL && !visited[node->next->id])
    // {
    //   node = node->next;
    //   printf("%d\n", graph->adjList[id].node->id);
    // }
    // else
    // {

    // }
  }
}*/

t_queue new_queue(t_graph *graph, int v)
{
  t_queue q;
  initQueue(&q);
  enqueue(&q, graph, v);
  while (!ifEmpty(&q))
  {
    graph->adjList[v].node = front(&q);
    dequeue(&q);
  }
  return (q);
}

void bfs(t_graph *graph, char **maze, int v)
{
  t_queue q;
  t_node *node;
  int i = 0;

  q = new_queue(graph, v);
  //printf("%s\n", "adazdazdazdad");
  while (ifEmpty(&q) == 1)
  {
    node = graph->adjList[v].node;
    maze[node->pos.y][node->pos.x] = 'o';
    //printf("%s\n", "aaxwcwxcwcxwxcxcwxcw");
    while (node->visited == 1 && node->next)
    {
      node->visited = 0;
      enqueue(&q, graph, v);
      node = node->next;
    }
    v = node->id;
    printf("node->id = %d\n", v);
    //printf("%s\n", "kcokkocskodcskocds");
    dequeue(&q);
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
  bfs(graph, maze, 0);
  while (maze[i])
    printf("%s\n", maze[i++]);
  return (0);
}
