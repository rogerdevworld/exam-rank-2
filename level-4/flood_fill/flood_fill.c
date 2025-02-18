typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

void    fill(char **tab, t_point size, int x, int y, char target)
{
    if (y < 0 || x < 0 || y >= size.y || x >= size.x || tab[y][x] != target)
        return ;
    tab[y][x] = 'F';
    fill(tab, size, x + 1, y, target);
    fill(tab, size, x - 1, y, target);
    fill(tab, size, x, y + 1, target);
    fill(tab, size, x, y - 1, target);

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin.x, begin.y, tab[begin.y][begin.x]);
}