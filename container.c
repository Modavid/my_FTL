/*
** container.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Mon Nov  7 15:57:07 2016 MO david
** Last update Fri Nov 11 13:37:12 2016 MO david
*/

#include "ftl.h"

int		add_container_to_ship(t_ship *ship)
{
  t_container	*node;

  my_putstr_color("magenta", "ajout du container en cours...\n");
  if ((node = malloc(sizeof(*node))) == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque ");
      my_putstr_color("red", "vous avez pose le container\n");
      return (0);
    }
  node->first = NULL;
  node->last = NULL;
  node->nb_elem = 0;
  ship->container = node;
  my_putstr_color("green", "le container a ete ajoute avec succes!\n");
  return (1);
}

void		add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == NULL && ship->container->last == NULL)
    {
      ship->container->first = freight;
      freight->next = NULL;
      freight->prev = NULL;
    }
  else
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      freight->next = NULL;
    }
  ship->container->last = freight;
  ship->container->nb_elem = ship->container->nb_elem + 1;
}

void		del_freight_from_container(t_ship *ship, t_freight *freight)
{
  t_freight	*tmpnext;
  t_freight	*tmpprev;
  t_freight	*tmp;

  tmp = freight;
  tmpnext = freight->next;
  tmpprev = freight->prev;
  if (tmp->next != NULL)
    tmp->next->prev = tmpprev;
  else
    ship->container->last = tmp->prev;
  if (tmp->prev != NULL)
    tmp->prev->next = tmpnext;
  else
    ship->container->first = tmp->next;
  free(tmp);
  ship->container->nb_elem -= 1;
}

void		get_bonus2(t_ship *ship)
{
  t_freight	*tmp2;
  
  while (ship->container->nb_elem > 0)
    {
      if (my_strcmp(ship->container->last->item, "attackbonus") == 0)
	ship->weapon->damage += 5;
      else if (my_strcmp(ship->container->last->item, "evadebonus") == 0)
	ship->navigation_tools->evade += 3;
      else if (my_strcmp(ship->container->last->item, "energybonus") == 0)
	ship->ftl_drive->energy += 1;
      tmp2 = ship->container->last->prev;
      free(ship->container->last->item);
      free(ship->container->last);
      ship->container->last = tmp2;
      ship->container->nb_elem -= 1;
    }
}
void		get_bonus(t_ship *ship)
{
  if (ship->container->last != NULL)
    {
      ftl_aff_bonus(ship);
      get_bonus2(ship);
      ship->container->first = NULL;
      ftl_aff_stat(ship);
    }
  else
    my_putstr_color("red", "aucune cargaison a ouvrir\n");
}
