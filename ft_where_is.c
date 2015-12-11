#include "fillit.h"

int		ft_is_around(char *buf, int i, int len)
{
	if (ft_is_left(buf, i) != 0)
		return (-1);
	if (ft_is_right(buf, i) != 0)
		return (1);
	if (ft_is_top(buf, i) != 0)
		return (-5);
	if (ft_is_bottom(buf, i, len) != 0)
		return (5);
	return (0);
}

int		ft_is_left(char *buf, int i)
{
	if (i - 1 >= 0 && buf[i - 1] == '#')
		return (-1);
	else
		return (0);
}

int		ft_is_right(char *buf, int i)
{
	if (buf[i + 1] == '#')
		return (1);
	else
		return (0);
}

int		ft_is_top(char *buf, int i)
{
	if (i - 5 >= 0 && buf[i - 5] == '#')
		return (-5);
	else
		return (0);
}

int		ft_is_bottom(char *buf, int i, int len)
{
	if (i + 5 >= len && buf[i + 5] == '#')
		return (5);
	else
		return (0);
}
