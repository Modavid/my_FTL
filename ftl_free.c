/*
** ftl_free.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Fri Nov 11 12:26:47 2016 MO david
** Last update Fri Nov 11 13:39:53 2016 MO david
*/

#include "ftl.h"

void		ftl_free(t_ship *ship)
{
  t_freight	*tmp;
  
  free(ship->enemy);
  if (ship->container->last != NULL)
    {
      while (ship->container->last != NULL)
	{
	  tmp = ship->container->last->prev;
	  free(ship->container->last->item);
	  free(ship->container->last);
	  ship->container->last = tmp;
	}
    }
  free(ship->container);
  free(ship->weapon->system_state);
  free(ship->navigation_tools->system_state);
  free(ship->ftl_drive->system_state);
  free(ship->navigation_tools);
  free(ship->weapon);
  free(ship->ftl_drive);
  free(ship);
}
