/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:22:00 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/19 20:22:00 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	push:
*	Empuja el elemento de arriba del bloque origen al bloque destino
*/
static void	push(t_bloques **origen, t_bloques **destino)
{
	t_bloques	*temporal;

	if (*origen == NULL)
		return ;
	temporal = (*origen)->siguiente;
	(*origen)->siguiente = *destino;
	*destino = *origen;
	*origen = temporal;
}

/*	ft_pa:
*	Empuja el elemento de arriba del bloque b al principio del bloque a
*	Muestra por pantalla "pa"
*/
void	ft_pa(t_bloques **bloque_a, t_bloques **bloque_b)
{
	push(bloque_b, bloque_a);
	ft_putstr("pa\n");
}

/*	ft_pb:
*	Empuja el elemento de arriba del bloque a al principio del bloque b
*	Muestra por pantalla "pb"
*/
void	ft_pb(t_bloques **bloque_a, t_bloques **bloque_b)
{
	push(bloque_a, bloque_b);
	ft_putstr("pb\n");
}
