/*
** air_shed.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:25:59 2016 MO david
** Last update Fri Nov 11 12:02:32 2016 MO david
*/

#include "ftl.h"
#include <stdlib.h>
#include <stdio.h>

t_ship		*create_ship()
{
  t_ship	*ship;

  my_putstr_color("magenta", "construction du vaisseau en cours...\n");
  if ((ship = malloc(sizeof(*ship))) == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre ");
      my_putstr_color("red", "construit par manque de materiaux\n");
      return (NULL);
    }
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  ship->enemy = NULL;
  ship->hull = 50;
  ship->etat = 0;
  ship->detect = 0;
  my_putstr_color("green", "amelioration du vaisseau termine!\n");
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*node;

  my_putstr_color("magenta", "ajout des armes en cours...\n");
  if ((node = malloc(sizeof(*node))) == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose quand vous ");
      my_putstr_color("red", "avez tente d'ajouter les armes\n");
      return (0);
    }
  node->system_state = my_strdup("online");
  node->damage = 10;
  ship->weapon = node;
  my_putstr_color("green", "les armes ont ete ajoutes avec succes!\n");
  return (1);
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*node;

  my_putstr_color("magenta", "ajout du reacteur en cours...\n");
  if ((node = malloc(sizeof(*node))) == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose ");
      my_putstr_color("red", "lorsque vous avez pose le reacteur\n");
      return(0);
    }
  node->system_state = my_strdup("online");
  node->energy = 10;
  ship->ftl_drive = node;
  my_putstr_color("green", "le reacteur a ete ajoute avec succes!\n");
  return(1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*node;

  my_putstr_color("magenta", "ajout des outils de navigations...\n");
  if ((node = malloc(sizeof(*node))) == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque");
      my_putstr_color("red", " vous avez pose les outils de navigations\n");
      return (0);
    }
  node->system_state = my_strdup("online");
  node->sector = 0;
  node->evade = 25;
  ship->navigation_tools = node;
  my_putstr_color("green", "les outils de navigations ont ete ");
  my_putstr_color("green", "ajoutes avec succes!\n");
  return (1);
}
