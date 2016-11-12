/*
** ftl_game2.c for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Wed Nov  9 14:34:26 2016 MO david
** Last update Fri Nov 11 12:09:28 2016 MO david
*/

#include "ftl.h"


int		ftl_jump(t_ship *ship)
{
  int		test;
  
  if (ship->etat == 1)
    {
      my_putstr_color("red","Vous tentez de fuir miserablement mais cela ce ");
      my_putstr_color("red", "fini par un echec cuisant\n");
    }
  else if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
    my_putstr_color("red", "WARNING: outils de navigation desactives\n");
  else if (my_strcmp(ship->ftl_drive->system_state, "online") != 0)
    my_putstr_color("red", "WARNING: reacteur endommagé\n");
  else
    {
      ftl_aff_jump();
      my_putstr("Nous sommes arrivé dans le secteur ");
      ship->navigation_tools->sector += 1;
      ship->ftl_drive->energy -= 1;
      my_put_nbr(ship->navigation_tools->sector);
      my_putstr("\n");
      ship->detect = 0;
      if ((test = enemy_encounter(ship)) == 1)
	return (1);
    }
  return (0);
}

void            ftl_lose_energy(t_ship *ship)
{
  my_putstr_color("red", "Dans un moment de desespoir, l'ennemi");
  my_putstr_color("red", " lance derniere une attaque qui touche");
  my_putstr_color("red", " votre réservoir de carburant\n");
  my_putstr_color("red", "vous avez perdu 1 d'energie\n");
  ship->ftl_drive->energy -= 1;
}

void            ftl_detect(t_ship *ship)
{
  int           i;
  t_freight     *node;

  i = 0;
  if (ship->etat == 1)
    my_putstr_color("red", "Vous etes en combat est ce vraiment le moment ?\n");
  else if (ship->detect == 0)
    {
      while (i < 10)
	{
	  node = create_freight();
	  add_freight_to_container(ship, node);
	  i++;
	}
      my_putstr_color("cyan", "Votre equipage a trouver une cargaison ");
      my_putstr_color("cyan", "mystérieuse.. Que peut elle bien contenir ?\n");
      ship->detect = 1;
    }
  else
    {
      my_putstr_color("red", "Vous continuez a chercher les fin fond de");
      my_putstr_color("red", " l'univers sans rien trouver\n");
    }
}

void		ftl_convert(t_ship *ship)
{
  if (ship->ftl_drive->energy > 2 && ship->hull <50)
    {
      my_putstr("Conversion de 1 energy pour 10 hull\n");
      ship->ftl_drive->energy -= 1;
      ship->hull += 10;
      if (ship->hull > 50)
	ship->hull = 50;
    }
  else if (ship->hull == 50)
    my_putstr("Votre vie est deja a 50\n");
  else
    my_putstr("Vous n'avez pas assez d'energie pour reparer puis voyager\n");
}
