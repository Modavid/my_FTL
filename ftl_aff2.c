/*
** ftl_aff2.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Thu Nov 10 20:26:38 2016 MO david
** Last update Fri Nov 11 12:20:11 2016 MO david
*/

#include "ftl.h"

void	aff_sys_rep()
{
  my_putstr_color("cyan", "Que voulez vous reparer ? \"ftl_drive\"");
  my_putstr_color("cyan", " | \"weapon\" | \"navigation_tools\" | \"all\"\n");
  my_putstr_color("blue", "my_ftl>repair_system>");
}

void	aff_end_game(t_ship *ship)
{
  if (ship->navigation_tools->sector == 10)
    my_putstr_color("yellow", "Bravo !! Vous avez terminé le jeu\n");
  if (ship->etat == 1 && ship->hull <= 0)
    my_putstr_color("red", "Votre vaisseau s'est fait destroy");
  if (ship->ftl_drive->energy == 0 && ship->navigation_tools->sector != 10)
    {
      my_putstr_color("red", "Le vaisseau tombe en panne par manque d'energie\n");
      my_putstr_color("red", "Vous etes rattrapé par la confrerie ");
      my_putstr_color("red", "et etes capture\n");
    }
  my_putstr_color("yellow", "\nMerci d'avoir joué, a bientot !\n");
}
