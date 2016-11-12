/*
** testeur.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Mon Nov  7 20:30:09 2016 MO david
** Last update Thu Nov 10 11:38:33 2016 MO david
*/

#include "ftl.h"

t_freight	*create_freight()
{
  t_freight	*node;
  int		rand;
  char		*item;
  
  node = malloc(sizeof(*node));
  rand = my_rand(100);
  item = "scrap";
  if (rand > 70)
    {
      rand = my_rand(100);
      if (rand >=1 && rand <= 33)
	item = "energybonus";
      else if (rand >= 34 && rand <= 66)
	item = "attackbonus";
      else if (rand >= 67 && rand <= 99)
	item = "evadebonus";
    }
  node->item = my_strdup(item);
  return (node);
}
