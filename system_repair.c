/*
** system_repair.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Tue Nov  8 10:05:01 2016 MO david
** Last update Fri Nov 11 15:34:49 2016 MO david
*/

#include "ftl.h"


int		ftl_drive_system_repair(t_ship *ship)
{
  my_putstr_color("magenta", "reparation du reacteur en cours...\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    {
      free(ship->ftl_drive->system_state);
      ship->ftl_drive->system_state = my_strdup("online");
      if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
	my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
      else
	{
	  my_putstr_color("red", "les reparations du reacteur ont echoue\n");
	  return (1);
	}
    }
  else 
    my_putstr_color("green", "le moteur n'a pas besoin d'etre reparer\n");
  return (0);
}

int		navigation_tools_system_repair(t_ship *ship)
{
  my_putstr_color("magenta", "reparation du ");
  my_putstr_color("magenta", "systeme de navigation en cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    {
      free(ship->navigation_tools->system_state);
      ship->navigation_tools->system_state = my_strdup("online");
      if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
	my_putstr_color("green", "reparation termine! systeme de navigation OK!\n");
      else
	{
	  my_putstr_color("red", "les reparations des ");
	  my_putstr_color("red", "outils de navigations ont echoue\n");
	  return (1);
	}
    }
  else 
    my_putstr_color("green", "systeme de navigation ne necessite pas repair\n");
  return (0);
}

int		weapon_system_repair(t_ship *ship)
{
  my_putstr_color("magenta", "reparation du systeme d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") != 0)
    {
      free(ship->weapon->system_state);
      ship->weapon->system_state = my_strdup("online");
      if (my_strcmp(ship->weapon->system_state, "online") == 0)
	my_putstr_color("green", "reparation termine! systeme d'armement OK!\n");
      else
	{
	  my_putstr_color("red", "les reparations du ");
	  my_putstr_color("red", "systeme d'armement ont echoue\n");
	  return (1);
	}
    }
  else
    my_putstr_color("green", "l'arme nest pas endommage, pew pew\n");
  return (0);
}

static const t_repair_command	repair[] =
  {
    {"ftl_drive", &ftl_drive_system_repair},
    {"navigation_tools", &navigation_tools_system_repair},
    {"weapon", &weapon_system_repair},
    {NULL, NULL}
  };

int		system_repair(t_ship *ship, int i, int j, int k)
{
  char		*entree;
  
  aff_sys_rep();
  entree = readline();
  if (entree == NULL)
    return (1);
  else
    {
      while (repair[i].str != NULL)
	{
	  if (my_strcmp(entree, repair[i].str) == 0
	      || my_strcmp(entree, "all") == 0)
	    {
	      k += repair[i].f(ship);
	      j = 1;
	    }
	  i++;
	}
    }
  if (repair[i].str == NULL && j == 0)
    my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue\n");
  if (k > 0)
    return (1);
  return (0);
}
