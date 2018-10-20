#include "fillit.h"

static t_tetri	*ft_block_xy(t_tetri *block, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_tetri			*ft_filling_xy(t_tetri *block)
{
	t_tetri	*tmp;

	tmp = block;
	while (block->next)
	{
		//ft_block_xy remplie dans la liste les cordone x , y des #
		block = ft_block_xy(block, ft_strsplit(block->str, '\n'));
		// on a plus besoin de str nous avon tt les cordonnée 
		ft_strdel(&block->str);
		block = block->next;
	}
	return (tmp);
}
