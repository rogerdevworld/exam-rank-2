#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *s)
{
	int		i = 0, j, k = 0, wc = 0;
	char	**res;

	while (s[i]) wc += (s[i] > 32 && (s[i + 1] <= 32 || !s[i + 1])), i++;
	res = malloc((wc + 1) * sizeof(char *));
	if (!res) return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] <= 32) i++;
		if (!s[i]) break ;
		j = i;
		while (s[j] && s[j] > 32) j++;
		res[k] = malloc(j - i + 1);
		int l = 0;
		while (i < j) res[k][l++] = s[i++];
		res[k++][l] = '\0';
	}
	res[k] = 0;
	return (res);
}

int	main(void)
{
	char **words = ft_split("  Hola   mundo  esto es  una prueba ");
	int i = 0;

	while (words[i])
	{
		printf("'%s'\n", words[i]);
		i++;
	}
	return (0);
}