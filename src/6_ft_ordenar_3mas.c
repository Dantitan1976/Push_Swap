/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_ordenar_3mas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:00:38 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/26 16:00:38 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_indice_mayor(t_bloques *bloque);

/*	ft_todo_menostres:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
static void	ft_todo_menostres(t_bloques **bloque_a, t_bloques **bloque_b)
{
	int	bloque_size_a;
	int	posicion;
	int	a_pila_b;

	bloque_size_a = ft_lstsize_ps(*bloque_a);
	posicion = 0;
	a_pila_b = 0;
	while (bloque_size_a > posicion && a_pila_b < bloque_size_a / 2)
	{
		if ((*bloque_a)->indice <= bloque_size_a / 2)
		{
			ft_pb(bloque_a, bloque_b);
			a_pila_b++;
		}
		else
			ft_ra(bloque_a);
		posicion++;
	}
	while (bloque_size_a - a_pila_b > 3)
	{
		ft_pb(bloque_a, bloque_b);
		a_pila_b++;
	}
}

/*	ft_cambiar_bloque_a:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	ft_cambiar_bloque_a(t_bloques **bloque_a)
{
	int	pos_indicemasbajo;
	int	bloque_a_size;

	bloque_a_size = ft_lstsize_ps(*bloque_a);
	pos_indicemasbajo = pos_indice_masbajo(bloque_a);
	if (pos_indicemasbajo < bloque_a_size / 2)
	{
		while (pos_indicemasbajo < bloque_a_size)
		{
			ft_rra(bloque_a);
			pos_indicemasbajo++;
		}
	}
	else
	{
		while (pos_indicemasbajo > 0)
		{
			ft_ra(bloque_a);
			pos_indicemasbajo--;
		}
	}
}

static int	ft_indice_mayor(t_bloques *bloque)
{
	int	index;

	index = bloque->indice;
	while (bloque)
	{
		if (bloque->indice > index)
			index = bloque->indice;
		bloque = bloque->siguiente;
	}
	return (index);
}

void	ft_ordenar_3mas(t_bloques **bloque_a, t_bloques **bloque_b)
{
	int	indice_mayor;

	indice_mayor = ft_indice_mayor(*bloque_a);
	if ((*bloque_a)->indice == indice_mayor)
	{
		ft_ra(bloque_a);
		if (ft_check_orden(*bloque_a))
			return ;
	}			
	if ((*bloque_a)->indice != indice_mayor)
	{
		ft_todo_menostres(bloque_a, bloque_b);
		ft_ordenar_3(bloque_a);
		while (*bloque_b)
		{
			ft_asigna_pos_obj(bloque_a, bloque_b);
			ft_coste_ba(bloque_a, bloque_b);
			ft_mov_mas_efic(bloque_a, bloque_b);
		}
		if (!ft_check_orden(*bloque_a))
			ft_cambiar_bloque_a(bloque_a);
	}
}
