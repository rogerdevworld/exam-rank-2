#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_strcpy(char *dest, char *src, int len)
{
    int i = 0;
    while (i < len)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    //count words
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    i = 0;
    char **split = (char **)malloc((count + 1) * sizeof(char *));
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        j = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        split[k] = malloc(i - j + 1);
        ft_strcpy(split[k++], &str[j], i - j);
    }
    split[k] = NULL;
    return (split);
}

int main()
{
    int i = 0;
    int j = 0;
    char **split  = ft_split("Hello World New Words Apply Yours Songs");
    while (split[i])
        i++;
    ft_putstr(split[--i]);
    while (j < i)
    {
        ft_putstr(" ");
        ft_putstr(split[j]);
        j++;
    }
    //ft_putstr("$");
    return 0;
}