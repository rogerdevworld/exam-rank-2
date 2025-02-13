#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int len)
{
	int i = 0;
	while(src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	count = 0;
	//contador de palabras 
	while(str[i])
	{
		while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		if (str[i])
			count++;
		while(str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
	}
	char **split = (char **)malloc((count + 1) * sizeof(char *));
	i = 0;
	while (str[i])
	{
		while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		j = i;
		while(str[i]  && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
		if (i > j)
		{
			split[k] = malloc((i - j + 1) * sizeof(char));
			ft_strncpy(split[k++], &str[j], i - j);
		}
	}
	split[k] = NULL;
	return (split);
}

/*
//min version
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
*/
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