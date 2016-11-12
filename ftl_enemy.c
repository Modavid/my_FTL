/*
** ftl_ennemy.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Wed Nov  9 15:31:36 2016 MO david
** Last update Fri Nov 11 11:05:36 2016 MO david
*/

#include "ftl.h"

int		create_enemy(t_ship *ship)
{
  t_enemy	*node;
  static int	dmg = 10;
  static int	hp = 20;
  
  if ((node = malloc(sizeof(*node))) == NULL)
    {
      my_putstr_color("red", "Erreur lors de la creation du vaisseau ennemi\n");
      return (1);
    }
  node->damage = dmg;
  node->hull = hp;
  ship->enemy = node;
  dmg *= 1.5;
  hp *= 1.5;
  return (0);
}

int		enemy_encounter(t_ship *ship)
{
  int		random;
  
  if (ship->navigation_tools->sector != 10)
    {
      random = my_rand(10);
      if (random == 1 || random == 4 || random == 7)
	{
	  if ((random = create_enemy(ship)) == 1)
	    return (1);
	  my_putstr_color("red", "Ennemi rencontré\n");
	  my_putstr("Damage :");
	  my_put_nbr(ship->enemy->damage);
	  my_putstr("\nHP :\t");
	  my_put_nbr(ship->enemy->hull);
	  my_putstr("\n");
	  my_putstr_color("red", "L'ennemi engage l'offensive\n");
	  ship->etat = 1;
	}
      else
	my_putstr_color("magenta", "Aucun ennemi a l'horizon\n");
    }
  return (0);
}

void		enemy_crit(t_ship *ship, int rand)
{
  if (rand == 1 && my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    {
      free(ship->ftl_drive->system_state);
      ship->ftl_drive->system_state = my_strdup("endommagé");
      my_putstr_color("red", "Le reacteur est endommage !\n");
    }
  else if (rand == 2 &&
	   my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    {
      free(ship->navigation_tools->system_state);
      ship->navigation_tools->system_state = my_strdup("endommagé");
      my_putstr_color("red", "Les systemes de navigation sont endommages !\n");
    }
  else if (rand == 3 && my_strcmp(ship->weapon->system_state, "online") == 0)
    {
      free(ship->weapon->system_state);
      ship->weapon->system_state = my_strdup("endommagé");
      my_putstr_color("red", "Le systeme d'armement est endommage !\n");
    }
}

void		enemy_attack(t_ship *ship)
{
  int		rand;

  rand = my_rand(100);
  
  if (rand < ship->navigation_tools->evade)
    my_putstr_color("cyan", "Manoeuvre d'esquive réussi\n");
  else
    {
      my_putstr_color("red", "L'ennemi lance une attaque photonique\n");
      my_putstr_color("red", "nous avons subis ");
      my_put_nbr(ship->enemy->damage);
      my_putstr_color("red", " dommages\n");
      ship->hull -= ship->enemy->damage;
      rand = my_rand(5);
      if (rand == 3)
	{
	  rand = my_rand(3);
	  enemy_crit(ship, rand);
	}
    }
}

void		ftl_attack(t_ship *ship)
{
  int		rand;
  
  if (ship->etat != 1)
    my_putstr_color("red", "PROFESSOR OAK :This isn't the time to use that\n");
  else if (my_strcmp(ship->weapon->system_state, "online") != 0)
    my_putstr_color("red", "le canon photo est endommagé !\n");
  else
    {
      ship->enemy->hull -= ship->weapon->damage;
      my_putstr_color("yellow", "Vous avez infliges ");
      my_put_nbr(ship->weapon->damage);
      my_putstr_color("yellow", " dommages\n");
      if (ship->enemy->hull <= 0)
	{
	  if ((rand = my_rand(2)) == 1)
	    ftl_lose_energy(ship);
	  my_putstr_color("green", "L'ennemi est mort, gloire a l'empire !\n");
	  ship->etat = 0;
	  free(ship->enemy);
	}
    }
}
