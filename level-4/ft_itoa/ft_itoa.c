#include <stdlib.h>

void ft_itoa_re(int n, char *str, int &i)
{
    if (n == -2147483648)
    {
        str[(*i)++] = '-';
        str[(*i)++] = '2';
        ft_itoa_re(147483648, str, i);
    }
    else
    {
        if (n < 0)
        {
            str[(*i)++] = '-';
            n = -n;
        }
        if (n > 9)
            ft_itoa_re(n / 10, str, i);
        str[(*i)++] = (n % 10) + '0';
    }
}
char *ft_itoa(int n)
{
    int i = 0;
    char *str;
    str = malloc(12);
    if (!str)
        return (NULL);
    ft_itoa_re(n, str, &i);
    str[i] = '\0';
    return (str);    
}