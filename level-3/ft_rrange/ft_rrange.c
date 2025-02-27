#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*range;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (0);
	i = len;
	while (i--)
	{
		if (start < end)
			range[i] = start++;
		else
			range[i] = start--;
		// i++;
	}
	return (range);
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	*range;

	if (argc != 4)
	{
		printf("./a.out <len> <start> <end>");
		return (0);
	}
	i = 0;
	len = atoi(argv[1]);
	range = ft_rrange(atoi(argv[2]), atoi(argv[3]));
	while (len > i)
	{
		printf("%d\n", range[i]);
		i++;
	}
}
