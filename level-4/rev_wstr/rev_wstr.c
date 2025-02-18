#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_strncpy(char *dest, char *src, int len)
{
    int i = 0;

    while (src[i] && i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    while (str[i])
    {
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    char **split = (char **)malloc((count + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    i = 0;
    while (str[i])
    {
        while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        j = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        split[k] = malloc(i - j + 1);
        ft_strncpy(split[k++], &str[j], i - j);
    }
    split[k] = NULL;
    return (split);

}

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return (len);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        char **split = ft_split(argv[1]);
        while (split[i])
            i++;
        while (i--)
        {
            write(1, split[i], ft_strlen(split[i]));
            if (i != 0)
                write(1, " ", 1);
        }
        free(split);
    }
    write(1, "\n", 1);
}