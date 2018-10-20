#include "fillit.h"

static	char	**ft_refill_point(char **tab, t_tetri *block, int max)
{
	int			x;
	int			y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == block->c)
				tab[y][x] = '.';
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	return (tab);
}

static char		**ft_print(char **tab, t_tetri *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				tab[y][x] = block->c;
				i++;
			}
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

static int		ft_check_xy(char **tab, t_tetri *block, int max)
{
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static t_tetri			*ft_update_xy(t_tetri *block, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = block->x[0];
	ymin = block->y[0];
	i = 1;
	while (i != 4)
	{
		if (block->x[i] < xmin)
			xmin = block->x[i];
		if (block->y[i] < ymin)
			ymin = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - xmin + x;
		block->y[i] = block->y[i] - ymin + y;
		i++;
	}
	return (block);
}

static char		**ft_rule(char **tab, t_tetri *block, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!block->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			block = ft_update_xy(block, x, y);
			if (ft_check_xy(tab, block, max))
				tmp = ft_rule(ft_print(tab, block, max), block->next, max);
			if (tmp)
				return (tmp);
			tab = ft_refill_point(tab, block, max);
			x++;
		}
		y++;
	}
	return (NULL);
}

static char			**ft_fill_point(char **tab, int max)
{
	int y;
	int x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char			**ft_result(t_tetri *block, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{

		/*
		 * max est la taille de plus petit caree quand peux avoir pour 
		 * cette cas un tetrimos cube . et si marche pas en augmente le carre 
		 * par 1 jusqua arrive au bon resultat
		*/
	
		//alloue et remplir el matrice tab par des '.'
		tab = ft_fill_point(tab, max);
		tab = ft_rule(tab, block, max);
		max++;
	}
	return (tab);
}
