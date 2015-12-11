#include "fillit.h"

int		ft_find_third(char *buf, int i, int len)
{
	if (ft_is_around(buf, i, len) != 0)
		return (ft_is_around(buf, i, len));
	else
		return (0);
}

int		ft_find_second(char *buf, int i, int len)
{
	if (ft_is_dual(buf, i, len) > 0)
		return (ft_is_dual(buf, i, len));
	if (ft_is_around(buf, i, len) > 0)
		return (ft_is_around(buf, i, len));
	return (0);
}

int		ft_is_dual(char *buf, int i, int len)
{
	if (ft_is_left(buf, i) != 0 && ft_is_right(buf, i) != 0)		//droite et gauche
		return (6);
	if (i - 5 >= 0 && buf[i - 1] == '#' && buf[i - 5] == '#')	 	//gauche et haut
		return (7);
	if (ft_is_left(buf, i) != 0 && ft_is_bottom(buf, i, len) != 0)		//gauche et bas
		return (8);
	if (ft_is_right(buf, i) != 0 && ft_is_bottom(buf, i, len) != 0)		//droite et bas
		return (9);
	if (ft_is_right(buf, i) != 0 && ft_is_top(buf, i) != 0)		//droite et haut
		return (10);
	if (ft_is_top(buf, i) != 0 && ft_is_bottom(buf, i, len) != 0)		//haut et bas
		return (11);
	return(0);
}

int			ft_find_first(char *buf, int i, int len)
{
	if (ft_is_dual(buf, i, len) > 0)
		return (ft_is_dual(buf, i, len));
	if (ft_is_around(buf, i, len) > 0)
		return (ft_is_around(buf, i, len));
	return (0);
}

t_flist		*ft_find_type(char *buf, t_flist *begin_list)
{
	int	i;
	int n;
	int	len;
	t_flist	*link;

	link = begin_list;
	i = 0;
	len = ft_strlen(buf);
	while (len / 21 > 0)
	{
		while (buf[i] != '#')
		{
			if (ft_find_first(buf, i, len) > 5)
			{
				ft_fill_dual(ft_find_first(buf, i, len), link);
				if (ft_find_third(buf, i + ft_is_right(buf, i), len) != 0)
					link->x3 = ft_find_third(buf, i + ft_is_right(buf, i), len);
				else if (ft_find_third(buf, i + ft_is_bottom(buf, i, len), len) != 0)
					link->x3 = ft_find_third(buf, i + ft_is_bottom(buf, i, len), len);
				else
				{
					begin_list = NULL;
					return (begin_list);
				}
			}
			else if (ft_find_first(buf, i, len) != 0 && ft_find_first(buf, i, len) <= 5)
			{
				link->x1 = ft_is_around(buf, i, len);
				if (ft_find_second(buf, i + ft_find_first(buf, i, len), len) > 5) 
					ft_fill_dual_two(ft_find_second(buf, i, len), link);
				else if (ft_find_second(buf, i + ft_find_first(buf, i, len), len) < 5)
				{
					link->x2 = ft_find_second(buf, (i + ft_find_first(buf, i, len)), len);
					link->x3 = ft_find_third(buf, i + ft_find_first(buf, i, len) + ft_find_second(buf, i + ft_find_first(buf, i, len), len), len);
				}
				else
				{
					begin_list->next = NULL;
					return (NULL);
				}
			}
			else
			{
				begin_list = NULL;
				return (NULL);
			}
			i++;
		}
		len = len / 21;
	}
	return (begin_list);
}
