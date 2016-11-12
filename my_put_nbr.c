/*
** my_put_nbr.c for  in /home/mod/devc/c05/my_put_nbr
** 
** Made by MO david
** Login   <mo_d@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:23:03 2016 MO david
** Last update Thu Nov 10 21:35:01 2016 MO david
*/

#include <stdio.h>

void	my_putchar(char c);

int	n_min(int n)
{
  if (n == -2147483648)
    {
      my_putchar('-');
      my_putchar('2');
      n = 147483648;
    }
  return (n);
}
void	my_put_nbr(int n)
{
  int	div;
  int	i;
  
  div = 1;
  n = n_min(n);
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  i = n;
  while (i >= 10)
    {
      div = div * 10;
      i = i / 10;
    }
  while (div > 0)
    {
      my_putchar(((n / div) % 10) + '0');
      div = div / 10;
    }
}
