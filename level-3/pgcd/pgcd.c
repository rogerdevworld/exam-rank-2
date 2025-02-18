#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int tmp, mayor, menor;
        if (atoi(argv[1]) > atoi(argv[2]))
        {
            mayor = atoi(argv[1]);
            menor = atoi(argv[2]);
        }
        else
        {
            menor = atoi(argv[1]);
            mayor = atoi(argv[2]);
        }
        while (menor)
        {
            tmp = menor;
            menor = mayor % menor;
            mayor = tmp;
        }
        printf("%d", mayor);
    }
    printf("\n");
}