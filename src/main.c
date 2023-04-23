/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:13:36 by dramirez          #+#    #+#             */
/*   Updated: 2023/04/05 00:57:50 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	push_swap:
*	Elige el metodo de ordenación dependiendo del número
*	de valores a ordenar
*/
static void	ft_push_swap(t_bloques **bloque_a, t_bloques **bloque_b,
				int bloque_size)
{
	bloque_size = ft_lstsize_ps(*bloque_a);
	if (bloque_size == 2 && !ft_check_orden(*bloque_a))
		ft_sa(bloque_a);
	else if (bloque_size == 3 && !ft_check_orden(*bloque_a))
		ft_ordenar_3(bloque_a);
	else if (bloque_size > 3 && !ft_check_orden(*bloque_a))
		ft_ordenar_3mas(bloque_a, bloque_b);
}

void	ft_imprimirlista(t_bloques *cabeza)
{
	while (cabeza != NULL)
	{
		printf("%d ", cabeza->numero);
		cabeza = cabeza->siguiente;
	}
	printf("\n");
}

void	ft_leaks(void)
{
	system ("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_bloques	*bloque_a;
	t_bloques	*bloque_b;
	int			bloque_size;
	char		**split;

	bloque_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split[0])
			ft_error(NULL, NULL);
		ft_check_args(ft_numseparad(argv[1], ' '), split);
		bloque_a = ft_datosenlista_num(ft_numseparad(argv[1], ' '), split);
	}
	else if (argc > 2)
	{
		ft_check_args_int(argc, argv);
		bloque_a = ft_datosenlista_int(argc, argv);
	}
	bloque_size = ft_lstsize_ps(bloque_a);
	ft_indices(bloque_a, bloque_size + 1);
	ft_push_swap(&bloque_a, &bloque_b, bloque_size);
	return (ft_liberarbloques(&bloque_a), ft_liberarbloques(&bloque_b), 0);
}
