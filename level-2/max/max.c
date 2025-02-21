int	max(int *tab, unsigned int len)
{
	int res;
	int i = 1;

	if (len == 0)
		return (0);
	res = tab[0];
	while (len >= i)
	{
		if (res < tab[i])
			res = tab[i];
		i++;
	}
	return (res);
}