/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:36:24 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/07 12:27:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_raise_ij(int i, int j)
{
	i++;
	j++;
}

static int		ft_checkblock(char *buf, int i)
{
	int j;
	int k;

	j = 0;
	while (j < 20)
	{
		k = -1;
		while (k++ < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
			else
				ft_raise_ij(i, j);
		}
		if (buf[i] != '\n')
			return (0);
		else
			ft_raise_ij(i, j);
	}
	return (1);
}

static int		ft_checkchar(char *buf)
{
	int	i;
	int j;
	int len;
	int	n;

	len = (int)ft_strlen(buf);
	while (i < len)
	{
		j = -1;
		n = 0;
		while (j++ < 20)
		{
			if (buf[i] == '#')
			{
				n++;
				ft_raise_ij(i, j);
			}
			else
				ft_raise_ij(i, j);
		}
		if (n != 4)
			return (0);
		i = i + 2;
	}
	return (1);
}


static int		ft_checkgrid(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
			if (ft_checkblock(buf, i) == 0)
				return (0);
			else
				i = i + 21;
			if (buf[i] != '\n' && buf [i] != '\0')
				return (0);
			else
				i++;
	}
	return (1);
}

char	*ft_read(char **argv)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = open((const char*)argv[1], O_RDONLY);
	buf = (char*)malloc(sizeof(*buf) * BUF_SIZE);
	if (buf == NULL)
		return (NULL);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	close(fd);
	if (ft_checkgrid(buf) == 0 || ft_checkchar(buf) == 0)
		buf = '\0';
	return (buf);
}
