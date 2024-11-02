#include <strlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++
    return (len);
}

int count_word(const char *s, c)
{
    int count = 0;
    while(*s)
    {
        while(*s == c)
            s++
        if (*s)
        {
            count++;
            while(*s && s != c)
                s++;
        }
    }
    return (count);
}

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pointer;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup("")); // Devolver una cadena vacía
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	pointer = malloc(len + 1);
	if (!pointer)
		return (NULL);
	ft_strncpy(pointer, s + start, len);
	pointer[len] = '\0';
	return (pointer);
}


char	**ft_split(char const *s, char c)
{
	int		i = 0;
	int		start;
	char	**split;

	if (!s || !(split = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		start = (int)(s - (char *)s); // Guardar la posición de inicio de la palabra
		if (*s)
		{
			while (*s && *s != c)
				s++;
			split[i++] = ft_substr(s - (s - start), start, s - start);
		}
	}
	split[i] = NULL;
	return (split);
}