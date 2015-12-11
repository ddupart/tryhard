#include "fillit.h"

void		ft_fill_dual(int n, t_flist *link)
{
	if (n == 6)
	{
		link->x1 = 1;
		link->x2 = -1;
	}
	if (n == 8)
	{
		link->x1 = -1;
		link->x2 = 5;
	}
	if (n == 9)
	{
		link->x1 = 1;
		link->x2 = 5;
	}
	if (n == 10)
	{
		link->x1 = 1;
		link->x2 = -5;
	}
	if (n == 11)
	{
		link->x1 = -5;
		link->x2 = 5;
	}	
}

void		ft_fill_dual_two(int n, t_flist *link)
{
	if (n == 6)
	{
		link->x2 = 1;
		link->x3 = -1;
	}
	if (n == 8)
	{
		link->x2 = -1;
		link->x3 = 5;
	}
	if (n == 9)
	{
		link->x2 = 1;
		link->x3 = 5;
	}
	if (n == 10)
	{
		link->x2 = 1;
		link->x3 = -5;
	}
	if (n == 11)
	{
		link->x2 = -5;
		link->x3 = 5;
	}
}
