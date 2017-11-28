##
## Makefile for  in /home/arnould_b/Igraph
## 
## Made by jean-michel arnould
## Login   <arnould_b@epitech.net>
## 
## Started on  Mon Dec 21 09:21:05 2015 jean-michel arnould
## Last update Tue Feb 16 17:28:09 2016 Arnould Jean-Michel
##

NAME		:=	marienbad

CC		:=	gcc
RM		:= 	rm -f

SRC_DIR		:= 	src
OBJ_DIR		:=	obj
INC_DIR		:=	inc

CFLAGS		:=	-Wextra -Wall -Werror -g
CFLAGS		:=	-g
CFLAGS		+=	-I$(INC_DIR)

LDFLAGS		:=	-Llib/ -lmy

SRC		:=	main.c\
			get_next_line.c\
			tools.c\
			errors.c

SRC		:=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ		:=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))


$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -c -o $@ $<

all:			$(NAME)


$(NAME): 		$(OBJ2) $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)
			$(RM) $(SRC_DIR)/*~
			$(RM) $(OBJ_DIR)/*~
			$(RM) $(INC_DIR)/*~
			$(RM) *~
			$(RM) $(SRC_DIR)/*\#
			$(RM) $(OBJ_DIR)/*\#
			$(RM) $(INC_DIR)/*\#
			$(RM) *\#

fclean: 		clean
			$(RM) $(NAME)
			$(RM) $(NAME2)

re:			fclean all

.PHONY: 		all clean fclean re
