#include "fillit.h"

size_t	ft_valid_check(char *str, size_t i)
{
	size_t point;
	size_t diese;
	size_t endl;

	point = 0;
	diese = 0;
	endl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			point++;
		else if (str[i] == '#')
			diese++;
		else if (str[i] == '\n')
			endl++;
		else
			ft_error();
		if ((str[i] == '\n') && (str[i + 1] == '\n') && (endl + 1) % 5)
			ft_error();
		i++;
	}
	if (diese < 4 || point % 4 || diese % 4 || (endl + 1) % 5)
		ft_error();
	return (diese / 4);
}

static	size_t		ft_count(char *s)
{
	size_t			i;

	i = 0;
	while (*s)
	{
		if (*s == 'x')
			i++;
		s++;
	}
	return (i);
}

static	char	*ft_dies_ix(int i, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = ft_dies_ix(i + 1, s);
	}
	if (s[i - 1] > 0 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = ft_dies_ix(i - 1, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = ft_dies_ix(i + 5, s);
	}
	if (i - 5 > 0 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = ft_dies_ix(i - 5, s);
	}
	if (s[i] == '#')
		s[i] = 'x';
	return (s);
}

void	ft_plus_check(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '#')
		i++;
	s[i] = 'x';
	//ft_dies_ix = convert '#' to 'x'  (rien de special )
	s = ft_dies_ix(i, s);
	//compte les nombre de 'x'
	if (ft_count(s) != 4)
		ft_error();
	//return les '#'
	while (*s)
	{
		if (*s == 'x')
			*s = '#';
		s++;
	}
	}
