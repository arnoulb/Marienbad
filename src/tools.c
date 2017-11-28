/*
** tools.c for  in /home/daelomin/rendu/CPE/CPE_2015_Allum1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Tue Feb 16 16:05:30 2016 Arnould Jean-Michel
** Last update Mon Feb 22 20:45:43 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "function.h"
#include "my.h"

int	nb_match_line(char *str)
{
  int	i;
  int	nb_matches;

  nb_matches = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '|')
	++nb_matches;
      ++i;
    }
  return (nb_matches);
}

void	player_turn(char **line, char **matches, char **plat)
{
  int	test;

  test = 1;
  while (test == 1)
    {
      while (test == 1)
  	{
	  my_printf("Line: ");
	  line[0] = get_next_line(0);
	  if (!is_valid(line[0]))
	      free(line[0]);
	  else
	    test = -1;
	}
      test = 1;
      my_printf("Matches: ");
      matches[0] = get_next_line(0);
      if (!is_valid2(matches[0], my_getnbr(line[0]), plat))
	{
	  free(line[0]);
	  free(matches[0]);
	}
      else
	test = 0;
    }
}

void	ia_turn(char **line, char **matches, char **plat)
{
  int	i;

  i = 1;
  line[0] = malloc(sizeof (char) * 2);
  matches[0] = malloc(sizeof (char) * 2);
  while (i < 5 && nb_match_line(plat[i]) <= 0)
    ++i;
  matches[0][0] = nb_match_line(plat[i]) + '0';
  matches[0][1] = 0;
  line[0][0] = i + '0';
  line[0][1] = 0;
}

int	nb_matches(char **plat)
{
  int	i;
  int	j;
  int	nb_match;

  i = 0;
  nb_match = 0;
  while (plat[i])
    {
      j = 0;
      while (plat[i][j])
	{
	  if (plat[i][j] == '|')
	    nb_match += 1;
	  ++j;
	}
      ++i;
    }
  return (nb_match);
}

void	update_plat(char **plat, int line, int match)
{
  int	i;

  i = my_strlen(plat[line]);
  while (i > 0)
    {
      if (plat[line][i] == '|' && match > 0)
	{
	  plat[line][i] = ' ';
	  match--;
	}
      --i;
    }
}
