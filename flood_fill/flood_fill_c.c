void	fill(char **tab, t_point size, int x, int y, char target)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y || tab[y][x] != target)
		return ;
	fill(tab, size, x + 1, y);
	fill(tab, size, x - 1, y);
	fill(tab, size, x, y + 1);
	fill(tab, size, x, y - 1);
}
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	fill(tab, size, begin.x, begin.y, target); 
}
