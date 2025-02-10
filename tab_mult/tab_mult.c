#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int 	ft_atoi(char *str)
{
	int	i = 0;
	int	s = 1;
	int	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result *  10 + (str[i] - '0');
		i++;
	}
	return (result * s);
}

char *ft_itoa(int num) {
    char *result = malloc(12);
    int i = 0;

    if (!result)
        return NULL;

    if (num == -2147483648) {
        result[i++] = '-';
        result[i++] = '2';
        num = 147483648;
    }
    if (num < 0) {
        result[i++] = '-';
        num = -num;
    }
    if (num == 0) {
        result[i++] = '0';
    }
    int start = i;
    while (num > 0) {
        result[i++] = (num % 10) + '0';
        num /= 10;
    }
    result[i] = '\0';
    int end = i - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    return result;
}
int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	cal = 1;
		int	i = 1;
		int	tab = ft_atoi(argv[1]);
		while (i < 10)
		{
			write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
			write(1, " x ", 3);
			write(1, argv[1], ft_strlen(argv[1]));
			write(1, " = ", 3);
			cal = i * ft_atoi(argv[1]);
			write(1, ft_itoa(cal), ft_strlen(ft_itoa(cal)));
			if (i < 9)
				write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
