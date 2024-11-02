#include <unistd.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        int i = 0;
        int first_word_start = 0;
        int first_word_length = 0;

        // Omitir los espacios iniciales
        while (argv[1][i] == ' ')
            i++;
        
        first_word_start = i; // Guardamos el inicio de la primera palabra

        // Contar la longitud de la primera palabra
        while (argv[1][i] && argv[1][i] != ' ')
        {
            first_word_length++;
            i++;
        }

        // Omitir espacios entre la primera palabra y el resto
        while (argv[1][i] == ' ')
            i++;

        // Imprimir el resto de la línea
        while (argv[1][i])
        {
            if (argv[1][i] != ' ')
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
        
        // Imprimir un espacio y la primera palabra
        write(1, " ", 1);
        write(1, &argv[1][first_word_start], first_word_length);
    }
    write(1, "\n", 1);
    return 0;
}
