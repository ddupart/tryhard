#include "fillit.h"

int main(int argc, char **argv)
{
	t_flist	*begin_list;
	char	*buf;

	if (argc != 2)
		return (0);
	buf = ft_read(argv);
	if (buf[0] == '\0')
		return (0);
	begin_list = ft_create_list(buf);
	begin_list = ft_find_type(buf, begin_list);

	return (0);
}

