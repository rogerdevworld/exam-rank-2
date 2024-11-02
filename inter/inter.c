/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:42:13 by rmarrero          #+#    #+#             */
/*   Updated: 2024/10/29 21:31:56 by rmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	char p;

	if (argc == 3)
	{
		// Primer bucle: marca duplicados dentro de argv[1]
		while (argv[1][i])
		{
			p = argv[1][i];
			j = i + 1;
			while (argv[1][j])
			{
				if (p == argv[1][j])
					argv[1][j] = '@';
				j++;
			}
			i++;
		}

		// Segundo bucle: marca caracteres de argv[1] presentes en argv[2]
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j] && argv[1][i] != '@')
			{
				if (argv[1][i] == argv[2][j])
				{
					write(1, &argv[1][i], 1);
					break;  // Imprime y sale del bucle para evitar duplicados
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
