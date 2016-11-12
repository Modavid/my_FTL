##
## Makefile for  in /home/mod/devc/my_ftl
## 
## Made by MO david
## Login   <mo_d@etna-alternance.net>
## 
## Started on  Wed Nov  9 21:00:28 2016 MO david
## Last update Fri Nov 11 14:51:40 2016 MO david
##

CC		= gcc

NAME		= my_ftl

CFLAGS		= -Wextra -Wall -Werror

RM		= rm -f

SRC		= air_shed.c\
		  container.c\
		  create_freight.c\
		  ftl_aff.c\
		  ftl_enemy.c\
		  ftl_game2.c\
		  ftl_game.c\
		  main.c\
		  my_put_nbr.c\
		  my_string.c\
		  rand.c\
		  readline.c\
		  system_control.c\
		  system_repair.c\
		  ftl_aff2.c\
		  ftl_free.c\

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -I. $(CFLAGS) $(SRC) -o $(NAME)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:         all clean fclean re
