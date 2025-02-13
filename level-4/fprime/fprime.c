#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int n = atoi(argv[1]);
        int f = 2;
        int first = 1;
        
        if (n == 1)
            printf("1");
        
        while (n >= f)
        {
            if (n % f == 0)
            {
                if (!first)
                    printf("*");
                printf("%d", f);
                n /= f;
                first = 0;
            }
            else
                f++;
        }
    }
    printf("\n");
    return 0;
}