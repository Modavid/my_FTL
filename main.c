/*
** main.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Mon Nov  7 11:06:34 2016 MO david
** Last update Fri Nov 11 12:31:26 2016 MO david
*/

#include "ftl.h"

int		main()
{
  t_ship	*ship;
  int		k;
  
  srand(time(NULL));
  my_putstr_color("clear", "");
  if ((ship = create_ship()) == NULL)
    return (1);
  if ((k = add_weapon_to_ship(ship)) == 0)
    return (1);
  if ((k = add_ftl_drive_to_ship(ship)) == 0)
    return (1);
  if ((k = add_navigation_tools_to_ship(ship)) == 0)
    return (1);
  if ((k = add_container_to_ship(ship)) == 0)
    return (1);
  
  ftl_aff();
  k = ftl_boucle(ship);
  ftl_free(ship);
  if (k == 1)
    return (1);
  return (0);
}
