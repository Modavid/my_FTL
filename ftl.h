/*
** ftl.h for  in /home/mod/devc/my_ftl
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:21:38 2016 MO david
** Last update Fri Nov 11 12:31:41 2016 MO david
*/

#ifndef __FTL_H_
# define __FTL_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef struct	s_container
{
  t_freight	*first;
  t_freight	*last;
  int		nb_elem;
}		t_container;
 
typedef struct	s_navigation_tools
{
  char		*system_state;
  int		sector;
  int		evade;
}		t_navigation_tools;
  
typedef struct	s_ftl_drive
{
  char		*system_state;
  int		energy;
}		t_ftl_drive;

typedef struct	s_weapon
{
  char		*system_state;
  int		damage;
}		t_weapon;


typedef struct	s_enemy
{
  int		hull;
  int		damage;
}		t_enemy;

typedef struct		s_ship 
{
  int			hull;
  int			etat;
  int			detect;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
  t_enemy		*enemy;
}			t_ship;

typedef struct	s_repair_command
{
  char		*str;
  int		(*f)(t_ship *ship);
}		t_repair_command;

typedef struct	s_test_command
{
  char		*str;
  void		(*f)(t_ship *ship);
}		t_test_command;


void		my_put_nbr(int n);
char		*readline();
int		my_rand(int version);
int		my_strlen(const char *str);
void		my_putstr(const char *str);
void		my_putstr_color(const char *color, const char *str);
int		my_strcmp(const char *s1, const char *s2);
char		*my_strdup(char *str);
t_ship		*create_ship();
int		add_weapon_to_ship(t_ship *ship);
int		add_ftl_drive_to_ship(t_ship *ship);
int		add_navigation_tools_to_ship(t_ship *ship);
int		add_container_to_ship(t_ship *ship);
void		add_freight_to_container(t_ship *ship, t_freight *freight);
void		del_freight_from_container(t_ship *ship, t_freight *freight);
void		get_bonus(t_ship *ship);
void		system_control(t_ship *ship);
int		system_repair(t_ship *ship, int i, int j,int k);

int		create_enemy();
int		enemy_encounter(t_ship *ship);
void		enemy_attack(t_ship *ship);
void		ftl_convert(t_ship *ship);
void		ftl_detect(t_ship *ship);
void		ftl_lose_energy(t_ship *ship);
void		ftl_aff();
void		aff_sys_rep();
void		aff_end_game(t_ship *ship);
void		ftl_aff_stat(t_ship *ship);
void		ftl_aff_help();
void		ftl_aff_bonus(t_ship *ship);
void		ftl_exit(t_ship *ship);
void		ftl_attack(t_ship *ship);
void		ftl_detect(t_ship *ship);
int		ftl_jump(t_ship *ship);
void		ftl_aff_jump();
int		ftl_boucle(t_ship *ship);
void		ftl_test(char *entree, t_ship *ship);
t_freight	*create_freight();
void		ftl_free(t_ship *ship);
#endif
