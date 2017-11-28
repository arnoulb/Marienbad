/*
** function.h for  in /home/daelomin/rendu/CPE/CPE_2015_Allum1
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Thu Feb 11 10:58:55 2016 Arnould Jean-Michel
** Last update Tue Feb 16 17:56:42 2016 Arnould Jean-Michel
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

int	nb_matches(char **);
int	nb_match_line(char *);
void	update_plat(char **, int, int);
void	player_turn(char **, char **, char **);
void	ia_turn(char **, char **, char **);
int	is_valid(char *);
int	is_valid2(char *, int, char **);
void	free_turn(char *, char *);
#endif
