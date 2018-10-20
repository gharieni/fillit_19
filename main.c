#include "fillit.h"

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

t_tetri		*ft_fill(char *str)
{
	size_t		i;
	size_t		j;
	char		c;
	t_tetri		*block;
	t_tetri		*tmp;

	j = 0;
	c = 64; // code ascci 'A' 65
	i = 0;
	//ft_valid_check VERIFIE BIEN str et return le nombre des TET
	i = ft_valid_check(str, i);
	if (!(block = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = block;
	while (i-- > 0)
	{
		//prend 1 seul tetrimos
		tmp->str = ft_strndup(&str[j], 20);
		//ft_plus_check = verifie que il y'as 4 '#'
		ft_plus_check(tmp->str);
		tmp->c = ++c; //le char a afficher au resultat 
		j += 21;//avance au tetrimos suivant
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	//la liste est bien remplie avec tt les info
	return (block);
}

char     *ft_read(char *file)
{
	int	fd;
	size_t	i;
	char	tmp[680];
	char	buffer[2];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while (read(fd, buffer, 1))
	{
		tmp[i++] = buffer[0];
		if (i > 680)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

int			main(int argc, char **argv)
{
	t_tetri		*list;
	char		*str;
	char		**final;

	if (argc != 2)
	{
		ft_putstr("usage: chemin de fichier !!\n");
		exit(0);
	}
//lire depui le fichier remplie str mieux changer avec GNL
	str = ft_read(argv[1]);
	//avec ft_fill la liste "list" est bien remplie avec tt les info
	list = ft_fill(str);
	//ft_filling_xy = tt les cordonne remplie en suprimant le string 
	list = ft_filling_xy(list);
	//la le moitier du projet le backtracking dans ft_result qui return char**
	final = ft_result(list, 2);
	//juste affichage du resultat qui est stoke dans final
	while (*final)
		ft_putendl(*final++);
	return (0);
}
