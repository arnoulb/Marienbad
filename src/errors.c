/*
** errors.c for  in /home/daelomin/rendu/CPE/CPE_2015_Allum1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Tue Feb 16 17:24:25 2016 Arnould Jean-Michel
** Last update Tue Feb 16 17:52:31 2016 Arnould Jean-Michel
*/

#include <stdlib.h>
#include "function.h"
#include "my.h"

int	is_valid(char *str)
{
  int	nb;

  if (!str)
    {
      my_printf("Error: Empty string\n");
      return (0);
    }
  nb = my_getnbr(str);
  if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (nb == 0 || nb > 4)
    {
      my_printf("Error: this line is out of range\n");
      return (0);
    }
  else
    return (1);
}

void	free_turn(char *str, char *str2)
{
  free(str);
  free(str2);
}

int	is_valid2(char *str, int line, char **plat)
{
  int	nb;

  if (!str)
    {
      my_printf("Error: Empty string\n");
      return (0);
    }
  nb = my_getnbr(str);
  if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (0);
    }
  if (nb == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (0);
    }
  if (nb > nb_match_line(plat[line]))
    {
      my_printf("Error: not enough matches on this line\n");
      return (0);
    }
  else
    return (1);
}
