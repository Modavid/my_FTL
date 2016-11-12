/*
** ftl_game.c for  in /home/mod/devc/my_ftl
** 
1;2802;0c** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Wed Nov  9 10:20:45 2016 MO david
** Last update Fri Nov 11 15:33:13 2016 MO david
*/

#include "ftl.h"

static const t_test_command	test[] =
  {
    {"getbonus", &get_bonus},
    {"control", &system_control},
    {"stat", &ftl_aff_stat},
    {"help", &ftl_aff_help},
    {"exit", &ftl_exit},
    {"attack", &ftl_attack},
    {"detect", &ftl_detect},
    {"convert", &ftl_convert},
    {NULL, NULL}
  };

void		ftl_exit(t_ship *ship)
{
  ship->hull = 0;
}

void		ftl_test(char *entree, t_ship *ship)
{
  int		i;
  int		j;
  
  i = 0;
  j = 0;
  while (test[i].str != NULL)
    {
      if (my_strcmp(entree, "repair") == 0 || my_strcmp(entree, "jump") == 0)
	j = 1;
      if (my_strcmp(entree, test[i].str) == 0)
	{
	  test[i].f(ship);
	  j = 1;
	}
      i++;
    }
  if (test[i].str == NULL && j == 0)
    my_putstr_color("red", "WalLLah cette commande elle existe pas\n");
}

int		ftl_boucle(t_ship *ship)
{
  char		*entree;
  int		k;

  entree = "new";
  while ((ship->hull > 0 && ship->navigation_tools->sector != 10) &&
	 ship->ftl_drive->energy > 0)
    {
      my_putstr_color("blue", "my_ftl>");
      entree = readline();
      ftl_test(entree, ship);
      if (my_strcmp(entree, "repair") == 0)
	k = system_repair(ship, 0, 0, 0);
      if (my_strcmp(entree, "jump") == 0)
	k = ftl_jump(ship);
      if (k == 1)
	{
	  my_putstr_color("red", "[SYSTEM FAILURE] : le lecteur de ");
	  my_putstr_color("red", "commande est bloque\n");
	  return (1);
	}
      if (ship->etat == 1)
	enemy_attack(ship);
      free(entree);
    }
  aff_end_game(ship);
  return (0);
}
