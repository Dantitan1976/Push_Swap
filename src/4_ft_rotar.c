/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_rotar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:38:00 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/19 20:38:00 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	rotar:
*	Mandamos al final del stack el primer elemento*/
static void	rotar(t_bloques **bloque)
{
	t_bloques	*temporal;
	t_bloques	*cola;

	temporal = *bloque;
	*bloque = (*bloque)->siguiente;
	cola = ft_lstlast_ps(*bloque);
	temporal->siguiente = NULL;
	cola->siguiente = temporal;
}

void	ft_ra(t_bloques **bloque_a)
{
	rotar(bloque_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_bloques **bloque_b)
{
	rotar(bloque_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_bloques **bloque_a, t_bloques **bloque_b)
{
	rotar(bloque_a);
	rotar(bloque_b);
	ft_putstr("rr\n");
}
