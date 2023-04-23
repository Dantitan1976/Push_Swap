/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:50:22 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/19 19:50:22 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_bloques *bloque)
{
	int	temporal;

	if (bloque == NULL || bloque->siguiente == NULL)
		return ;
	temporal = bloque->numero;
	bloque->numero = bloque->siguiente->numero;
	bloque->siguiente->numero = temporal;
	temporal = bloque->indice;
	bloque->indice = bloque->siguiente->indice;
	bloque->siguiente->indice = temporal;
}

/* ft_sa:
*	Invierte los dos elementos que están al principio del bloque a
*	Muestra en pantalla "sa"
*/
void	ft_sa(t_bloques **bloque_a)
{
	swap(*bloque_a);
	ft_putstr("sa\n");
}

/*	ft_sb:
*	Invierte los dos elementos que están al principio del bloque b
*	Muestra en pantalla "sb"
*/
void	ft_sb(t_bloques **bloque_b)
{
	swap(*bloque_b);
	ft_putstr("sb\n");
}

/*	ft_ss:
*	Invierte los dos elementos que están al principio del bloque a y del b
*	Muestra en pantalla "ss"
*/
void	ft_ss(t_bloques **bloque_a, t_bloques **bloque_b)
{
	swap(*bloque_a);
	swap(*bloque_b);
	ft_putstr("ss\n");
}
