#include "flood_fill.h"

void fill(char **tab, t_point size, int x, int y, char obje)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y || tab[x][y] != obje)
		return;
	tab[x][y] = 'F';
	fill(tab, size, x + 1, y, obje);
	fill(tab, size, x - 1, y, obje);
	fill(tab, size, x, y + 1, obje);
	fill(tab, size, x, y - 1, obje);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	char obje = tab[begin.x][begin.y];
	fill(tab, size, begin.x, begin.y, obje);
}
