# ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./srcs/libft.h"

typedef struct		s_tetri
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

void				ft_error(void);
void				ft_plus_check(char *s);
char				*ft_read(char *file);
char				**ft_result(t_tetri *block, int max);
size_t				ft_valid_check(char *str, size_t i);
t_tetri				*ft_filling_xy(t_tetri *block);
t_tetri				*ft_fill(char *str);
char				*ft_strc(char const *s1, char s2);

# endif
