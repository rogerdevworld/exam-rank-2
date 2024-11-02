#include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}
char    *ft_strdup(char *src)
{
    int i = 0;
    char *copia;

    copia = malloc(ft_strlen(src) + 1);
    if (!copia)
        return (NULL);
    while (src[i])
    {
        copia[i] = src[i];
        i++;
    }
    copia[i] = '\0';
    return (copia);
}