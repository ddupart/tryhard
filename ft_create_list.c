#include "fillit.h"

t_flist			*ft_add_to_list(t_flist *begin_list)
{
	t_flist		*link;

	link = (t_flist*)malloc(sizeof(t_flist));
	if (!link)
		return (NULL);
	link->next = begin_list;
	return (link);
}

t_flist			*ft_create_list(char *buf)
{
	t_flist		*begin_list;
	int			len;

	len = (int)ft_strlen(buf);
	begin_list = (t_flist*)malloc(sizeof(t_flist));
	if (begin_list == NULL)
		return (NULL);
	begin_list->next = NULL;					//set du pointeur sur NULL
	while (len / 21 > 0)
	{
		begin_list = ft_add_to_list(begin_list);	//tant que ret[i] existe, on cree un nouveau maillon dans la liste
		len = len / 21;
	}
	return (begin_list);
}
