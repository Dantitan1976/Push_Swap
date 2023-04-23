/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_check_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:33:43 by dramirez          #+#    #+#             */
/*   Updated: 2023/04/04 11:39:37 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_numseparad(char *str, char separador)
{
	int	posicion;
	int	cant_nums;

	posicion = 0;
	cant_nums = 0;
	while (str[posicion])
	{
		if (str[posicion] != separador)
		{
			cant_nums++;
			while (str[posicion] && str[posicion] != separador)
				posicion++;
			if (str[posicion] == '\0')
				return (cant_nums);
		}
		posicion++;
	}
	return (cant_nums);
}

char	ft_check_dobles(int argc, char **argv)
{
	int	num_arg;
	int	fila_arg;
	int	resultado;

	num_arg = 0;
	while (num_arg < argc)
	{
		resultado = ft_atoi(argv[num_arg]);
		fila_arg = 0;
		while (fila_arg < argc)
		{
			if (ft_atoi(argv[num_arg]) == ft_atoi(argv[fila_arg])
				&& num_arg != fila_arg)
				return ('d');
			fila_arg++;
		}
		num_arg++;
	}
	return (resultado);
}

/*Chequeamos los dobles de una cadena de char
int	main(int argc, char **argv)
{
	int	argumentos;
	
	argumentos = 1;
	if (argc < 2)
		write(1, "Error\n", 6);
	if (argumentos < argc)
	{
		printf("ft_check_dobles: %c\n", ft_check_dobles(argc, argv));
		argumentos++;
	}
	return (0);
}
*/

void	ft_check_args(int argc, char **argv)
{
	int	num_arg;

	num_arg = 0;
	while (num_arg < argc)
	{
		if (ft_check_num(argv[num_arg]) == 'f'
			|| (ft_check_int(argv[num_arg]) > 2147483647
				|| ft_check_int(argv[num_arg]) < -2147483647))
			ft_error(NULL, NULL);
	num_arg++;
	}
	if (ft_check_dobles(argc, argv) == 'd')
		ft_error(NULL, NULL);
}

/*int	main(int argc, char **argv)
{
	int	argumentos;
	
	argumentos = 1;
	if (argc < 2)
		write(1, "Error\n", 6);
	if (argumentos < argc)
	{
		printf("ft_check_args: %c\n", ft_check_args(argc, argv));
		argumentos++;
	}
	return (0);
}*/
