/*
** ftl_aff.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:31:57 2016 MO david
** Last update Fri Nov 11 12:13:41 2016 MO david
*/

#include "ftl.h"

void		ftl_aff()
{
  my_putstr_color("cyan", "\nVous pouvez utiliser la commande \" help\" pour");
  my_putstr_color("cyan", "connaitre la liste des commandes disponible");
  my_putstr_color("cyan", "\nCependant cela vous consomera une action\n");
}

void		ftl_aff_stat(t_ship *ship)
{
  my_putstr_color("cyan", "Ship stat:\n");
  my_putstr_color("magenta", "Hull : \t\t");
  my_put_nbr(ship->hull);
  my_putstr_color("magenta", "\nDamage : \t");
  my_put_nbr(ship->weapon->damage);
  my_putstr_color("magenta", "\nEnergy : \t");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr_color("magenta", "\nSector : \t");
  my_put_nbr(ship->navigation_tools->sector);
  my_putstr_color("magenta", "\nEvade : \t");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\n");
  if (ship->etat == 1)
    {
      my_putstr_color("red", "l'ennemi profit de votre moment");
      my_putstr_color("red"," d'inattention pour attaquer\n");
    }
}

void		ftl_aff_help()
{
  my_putstr_color("cyan", "Commandes systemes disponible :\n");
  my_putstr("attack\t\tPermet d'attaquer les ennemis.\ndetect");
  my_putstr("\t\tRecherche le secteur en but de matériaux\n");
  my_putstr("jump\t\tActive un portail l'hyperespace pour ");
  my_putstr("avancer au secteur suivant\n");
  my_putstr("getbonus\tUtilise les matériaux trouve pour améliorer ");
  my_putstr("le vaisseau\n");
  my_putstr("control\t\tPermet de verifier le vaisseau\nrepair\t\t");
  my_putstr("Permet de reparer le vaisseau\nstat\t\tCaracteristique du ");
  my_putstr("vaisseau\nconvert\t\tConvertir de l'energy pour de la vie\n");
  my_putstr("help \t\tHelp, euh.. quoi d'autre ?\nexit");
  my_putstr_color("red", "\t\tfuir de cette guerre galactique\n");
}

void	ftl_aff_jump()
{
  int random;

  random = my_rand(3);
  if (random == 1)
    {
      my_putstr_color("yellow", "* bruit de micro* A tout l'equipage : nous ");
      my_putstr_color("yellow", "allons entrer en mode hyperespace soyez pret\n");
      my_putstr_color("yellow", "Chargement pour saut hyper espace fini, JUMP\n");
    }
  else if (random == 2)
    {
      my_putstr_color("yellow", "bzz.. propulseur supraluminique en marche\n");
      my_putstr_color("yellow", "porte hyperespace ouverte, en avant toute\n");
    }
  else if (random == 3)
    {
      my_putstr_color("yellow", "Engine faster than light active...\n");
      my_putstr_color("yellow", "Porte vers les etoiles activee stabilisation");
      my_putstr_color("yellow", "en cours...\nbouclier activé... JUMP\n");
    }
}

void		ftl_aff_bonus(t_ship *ship)
{
  t_freight	*tmp;
  int		i;

  i = 0;
  tmp = ship->container->last;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->item, "attackbonus") == 0)
	{
	  my_putstr_color("cyan", "Vous avez trouvé une caisse d'amélioration");
	  my_putstr_color("cyan", " pour votre canon photo.\n+5 damage\n");
	  i++;
	}
      else if (my_strcmp(tmp->item, "evadebonus") == 0)
	{
	  my_putstr_color("cyan", "Vous avez trouvé une caisse d'amélioration");
	  my_putstr_color("cyan", " pour votre GPS galactic.\n+3 evade\n");
	  i++;
	}
      else if (my_strcmp(tmp->item, "energybonus") == 0)
	{
	  my_putstr_color("cyan", "Vous avez trouvé une caisse d'amélioration");
	  my_putstr_color("cyan", " contenant une batterie E2PZ. \n+1 energy\n");
	  i++;
	}
      tmp = tmp->prev;
    }
  if (i == 0)
    my_putstr_color("red", "manque de chance vous n'avez rien trouvé d'utile\n");
}
