/*
** rand.c for  in /home/mod/devc/chifumi/chifumi
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Fri Oct 28 17:00:20 2016 MO david
** Last update Thu Nov 10 11:53:06 2016 MO david
*/

#include "ftl.h"

int	my_rand(int version)
{
  int	random;
  
  random = (rand() % version) + 1;
  return (random);
}
