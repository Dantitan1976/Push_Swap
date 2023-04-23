/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_rotar_reverso.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:58:39 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/19 20:58:39 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	ft_rotar_reverso:
*	Trae el último elemento bloque al primer lugar
*/
static void	ft_rotar_reverso(t_bloques **bloque)
{
	t_bloques	*temporal;
	t_bloques	*cola;
	t_bloques	*anterior_cola;

	cola = ft_lstlast_ps(*bloque);
	anterior_cola = ft_lstpenultimo(*bloque);
	temporal = *bloque;
	*bloque = cola;
	(*bloque)->siguiente = temporal;
	anterior_cola->siguiente = NULL;
}

void	ft_rra(t_bloques **bloque_a)
{
	ft_rotar_reverso(bloque_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_bloques **bloque_b)
{
	ft_rotar_reverso(bloque_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_bloques **bloque_a, t_bloques **bloque_b)
{
	ft_rotar_reverso(bloque_a);
	ft_rotar_reverso(bloque_b);
	ft_putstr("rrr\n");
}
