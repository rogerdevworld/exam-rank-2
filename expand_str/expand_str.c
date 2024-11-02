#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        int len = ft_strlen(argv[1]) - 1;
        
        while(len > 0 && argv[1][len] == ' ')
        {
            argv[1][len] = '\0';
            len--;
        }
        while(argv[1][i] == ' ')
            i++;
        while(argv[1][i])
        {
            if (argv[1][i] == ' ')
                write(1, "   ", 3);
            while(argv[1][i] == ' ')
                i++;
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}