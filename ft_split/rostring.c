#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
int	ft_strlen(char *str)
{
	int  i = 0;
	while(str[i])
		i++;
	return (i);
}
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	i = 1;
		char	**split = ft_split(argv[1]);
		
		while(split[i])
		{
			write(1, split[i], ft_strlen(split[i]));
			write(1, " ", 1);
			i++;
		}
		write(1, split[0], ft_strlen(split[0]));
	}
	write(1, "\n", 1);
	return 0;
}
