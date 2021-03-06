/*
** get_next_line.h for  in /home/daelomin/rendu/CPE/CPE_2015_getnextline
**
** Made by Arnould Jean-Michel
** Login   <daelomin@epitech.net>
**
** Started on  Mon Jan  4 16:21:10 2016 Arnould Jean-Michel
** Last update Sat Jan 16 23:44:22 2016 Arnould Jean-Michel
*/

#ifndef READ_SIZE
#define READ_SIZE (10)
#endif

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

char	*get_next_line(const int fd);
char	*get_next_line2(char*, int);
char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_strlen(char *);

#endif
