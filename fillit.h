/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:36:40 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/09 12:33:27 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 546

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

typedef struct			s_structlist
{
	int		x;
	int		x1;
	int		x2;
	int		x3;
	struct s_structlist	*next;
}						t_flist;

char	*ft_read(char **argv);
t_flist	*ft_create_list(char *buf);
t_flist	*ft_add_to_list(t_flist *begin_list);
void	ft_fill_dual(int n, t_flist *link);
void	ft_fill_dual_two(int n, t_flist *link);
char	**ft_create_map();
void	ft_clear_map(char **map);
void	ft_print_map(char **map);
int		ft_is_around(char *buf, int i, int len);
int		ft_is_right(char *buf, int i);
int		ft_is_left(char *buf, int i);
int		ft_is_top(char *buf, int i);
int		ft_is_bottom(char *buf, int i, int len);
t_flist	*ft_find_type(char *buf, t_flist *begin_list);
int		ft_find_first(char *buf, int i, int len);
int		ft_find_second(char *buf, int i, int len);
int		ft_find_third(char *buf, int i, int len);
int		ft_is_dual(char *buf, int i, int len);


#endif
