/*
** system_control.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Tue Nov  8 09:41:19 2016 MO david
** Last update Thu Nov 10 19:46:54 2016 MO david
*/

#include "ftl.h"

void		ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!\n");
}

void		navigation_tools_system_check (t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme de navigation en cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!\n");
}

void		weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!\n");
}

void		system_control(t_ship *ship)
{
  char		*entree;
  my_putstr_color("cyan", "Que voulez vous vérifier ? \"ftl_drive\" ");
  my_putstr_color("cyan", "| \"weapon\" | \"navigation_tools\" | \"all\"\n");
  my_putstr_color("blue", "my_ftl>control_system>");
  entree = readline();
  if (my_strcmp(entree, "ftl_drive") == 0)
    ftl_drive_system_check(ship);
  else if (my_strcmp(entree, "weapon") == 0)
    weapon_system_check(ship);
  else if (my_strcmp(entree, "navigation_tools") == 0)
    navigation_tools_system_check(ship);
  else if (my_strcmp(entree, "all") == 0)
    {
      ftl_drive_system_check(ship);
      weapon_system_check(ship);
      navigation_tools_system_check(ship);
    }
  else
    my_putstr_color("red", "Wallah ya une erreur commande inconnue\n");
}
