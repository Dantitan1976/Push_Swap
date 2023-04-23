/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_posiciones_coste.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:33:59 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/26 19:33:59 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* get_cost:
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of the B stack
*		cost_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/
void	ft_coste_ba(t_bloques **bloque_a, t_bloques **bloque_b)
{
	t_bloques	*temp_a;
	t_bloques	*temp_b;
	int			bloque_a_size;
	int			bloque_b_size;

	temp_a = *bloque_a;
	temp_b = *bloque_b;
	bloque_a_size = ft_lstsize_ps(temp_a);
	bloque_b_size = ft_lstsize_ps(temp_b);
	while (temp_b)
	{
		temp_b->coste_b = temp_b->posicion;
		if (temp_b->posicion > bloque_b_size / 2)
			temp_b->coste_b = (bloque_b_size - temp_b->posicion) * -1;
		temp_b->coste_a = temp_b->posicion_objetivo;
		if (temp_b->posicion_objetivo > bloque_a_size / 2)
			temp_b->coste_a = (bloque_a_size - temp_b->posicion_objetivo) * -1;
		temp_b = temp_b->siguiente;
	}	
}

/*	ft_mov_mas_efic:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/
void	ft_mov_mas_efic(t_bloques **bloque_a, t_bloques **bloque_b)
{
	t_bloques	*temp;
	int			mas_efic;
	int			coste_de_a;
	int			coste_de_b;

	temp = *bloque_b;
	mas_efic = INT_MAX;
	while (temp)
	{
		if (ft_num_abs(temp->coste_a) + ft_num_abs(temp->coste_b)
			< ft_num_abs(mas_efic))
		{
			mas_efic = ft_num_abs(temp->coste_a) + ft_num_abs(temp->coste_b);
			coste_de_a = temp->coste_a;
			coste_de_b = temp->coste_b;
		}
		temp = temp->siguiente;
	}
	ft_mover(bloque_a, bloque_b, coste_de_a, coste_de_b);
}
