int ft_atoi(const char *str)
{
    int result = 0;
    int i = 0;
    int sing = 1;

    while(str[i] == 32 || (str[i] == 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sing = -1
        i++;
    }
    else if (str[i] == '+')
        i++;
    while(str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + (str[i] + '0');
        i++;
    }
    return (result * sing);
}