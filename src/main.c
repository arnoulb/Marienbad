/*
** main.c for  in /home/daelomin/rendu/CPE/CPE_2015_Allum1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Feb 11 10:54:20 2016 Arnould Jean-Michel
** Last update Wed Feb 17 14:17:03 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include "function.h"
#include "my.h"
#include "get_next_line.h"

void	aff_star(char *plat)
{
  int	i;

  i = 0;
  while (i < 9)
    plat[i++] = '*';
  plat[i] = 0;
}

void	fill_plat(char **plat)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  aff_star(plat[i]);
  k = 4;
  while (++i <= 4)
    {
      j = -1;
      while (++j < 9)
	{
	  if (j < k || j > 8 - k)
	    plat[i][j] = (j == 0 || j == 8) ? '*' : ' ';
	  else
	    plat[i][j] = '|';
	}
      plat[i][j] = 0;
      --k;
    }
  aff_star(plat[i]);
  plat[i + 1] = 0;
}

void	aff_plat(char **plat)
{
  int	i;

  i = 0;
  while (plat[i])
    {
      my_printf("%s\n", plat[i]);
      ++i;
    }
}

int	turn(char **plat)
{
  char	*line;
  char	*matches;
  int	i;

  i = 0;
  while (nb_matches(plat) > 0)
    {
      if (i % 2 == 0)
	{
	  my_printf("Your turn:\n");
	  player_turn(&line, &matches, plat);
	  my_printf("Player removed %s match(es) from line %s\n", matches, line);
	}
      else
	{
	  my_printf("AI's turn...\n");
	  ia_turn(&line, &matches, plat);
	  my_printf("AI removed %s match(es) from line %s\n", matches, line);
	}
      update_plat(plat, my_getnbr(line), my_getnbr(matches));
      free_turn(line, matches);
      aff_plat(plat);
      i++;
    }
  return (i);
}

int	main()
{
  char	**plat;
  int	i;
  int	issue;

  plat = malloc(sizeof (char *) * 7);
  i = 0;
  while (i < 7)
    plat[i++] = malloc(sizeof (char) * 10);
  fill_plat(plat);
  aff_plat(plat);
  issue = turn(plat);
  my_printf((issue % 2 == 1) ? "You lost, too bad..\n" :
	 "I lost.. snif.. but I'll get you next time !!\n");
  i = 0;
  while (i < 7)
    free(plat[i++]);
  free(plat);
  return (42);
}
