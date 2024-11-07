#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i = 0;

	while(src[i] && i < size)
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
	int	count_words = 0;
	char	**split;

	/* delimitadores \n \t ' '*/
	if (!str)
		return (NULL);
	/* contador de palabras */
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
                	i++;
		if (str[i])
			count_words++;
		while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
	}
	split = (char **)malloc((coun_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while(str[i])
	{
		while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			i++;
		j = i;
		while (str[i] && str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
			i++;
		if (i > j)
		{
			split[k] = malloc((i - j) + 1);
			if (!split[k])
				return (NULL);
			ft_strncpy(split[k++], &str[j], i - j);
		}
	}
	split = NULL;
	return (split);
}
