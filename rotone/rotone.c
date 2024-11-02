/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:10:27 by rmarrero          #+#    #+#             */
/*   Updated: 2024/10/29 17:12:17 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
	        if (argv[1][i])
	        {
		        while(argv[1][i])
		        {
			        if (argv[1][i] == 'z' || argv[1][i] == 'Z')
			        {
				        argv[1][i] -= 25;
				        write(1, &argv[1][i], 1);
			        }
			        else if (argv[1][i] >= 65 && argv[1][i] <= 126)
			        {
				        argv[1][i] += 1;
				        write(1, &argv[1][i], 1);
			        }
			        else
			        {
				        write(1, &argv[1][i], 1);
			        }
			        i++;
		        }
			write(1, "\n", 1);
		}
		else
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
