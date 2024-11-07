#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	void	fill(int x, int y)
	{
		if (x <  0 || y < 0 || x >= size.x || y >=  size.y || tab[y][x] != target)
			return ;
		tab[y][x] = 'F';
		fill(x + 1, y);
		fill(x - 1, y);
		fill(x, y + 1);
		fill(x, y - 1);
	}
	fill(begin.x, begin.y);
}
