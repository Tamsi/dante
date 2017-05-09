/*
** main.c for main in /home/yoannk/dante/astar
** 
** Made by Yoann Kersulec
** Login   <yoann.kersulec@epitech.eu@epitech.eu>
** 
** Started on  Fri Apr 28 14:34:49 2017 Yoann Kersulec
** Last update Fri Apr 28 18:38:38 2017 Yoann Kersulec
*/

#include "astar.h"

int	algo_pd(char **maze, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i != x && j != y)
    {
      printf("%i -------- %i\n", i, j);
    }
  printf("X = %i\nY = %i\n", x, y);
  return (0);
}

char	**open_map(int fd)
{
  char **maze;
  int i;

  i = 0;
  maze = malloc (50 * sizeof(char *));
  while ((maze[i] = get_next_line(fd)))
    i++;
  return (maze);
}

int	main(int ac, char **av)
{
  int fd;
  int i;
  char **maze;

  i = 0;
  if (ac <= 1)
    return (84);
  if ((fd = open(my_strcat("../mazes/", av[1]), O_RDONLY)) == -1)
    return (84);
  maze = open_map(fd);
  while (maze[i])
    {
      printf("%s\n", maze[i]);
      i = i + 1;
    }
  //algo_pd(maze, my_strlen(maze[0]), i);
  return (0);
}
