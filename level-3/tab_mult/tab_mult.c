#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int r = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + (str[i] - '0');
        i++;
    }
    return (r);
}

void *ft_itoa(int n)
{
    char    c;

    if (n >= 10)
        ft_itoa(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 1;
    int cal = 0;
    if (argc == 2)
    {
        while (i <= 9)
        {
            ft_itoa(i);
            write(1, " x ", 3);
            ft_itoa(ft_atoi(argv[1]));
            write(1, " = ", 3);
            cal = i * ft_atoi(argv[1]);
            ft_itoa(cal);
            write(1, "\n", 1);
            i++;
        }
    }
    if (argc != 2)
        write(1, "\n", 1);

}