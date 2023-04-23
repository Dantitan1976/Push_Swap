/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_mover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:07:37 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/26 21:07:37 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_rotar_reverso_ambos(t_bloques **bloque_a, t_bloques **bloque_b,
										int *coste_a, int *coste_b)
{
	while (*coste_a < 0 && *coste_b < 0)
	{
		(*coste_a)++;
		(*coste_b)++;
		ft_rrr(bloque_a, bloque_b);
	}
}

static void	ft_rotar_ambos(t_bloques **bloque_a, t_bloques **bloque_b,
								int *coste_a, int *coste_b)
{
	while (*coste_a > 0 && *coste_b > 0)
	{
		(*coste_a)--;
		(*coste_b)--;
		ft_rr(bloque_a, bloque_b);
	}	
}

static void	ft_rotar_a(t_bloques **bloque_a, int *coste_a)
{
	while (*coste_a)
	{
		if (*coste_a > 0)
		{
			ft_ra(bloque_a);
			(*coste_a)--;
		}
		else if (*coste_a < 0)
		{
			ft_rra(bloque_a);
			(*coste_a)++;
		}
	}
}

static void	ft_rotar_b(t_bloques **bloque_b, int *coste_b)
{
	while (*coste_b)
	{
		if (*coste_b > 0)
		{
			ft_rb(bloque_b);
			(*coste_b)--;
		}
		else if (*coste_b < 0)
		{
			ft_rrb(bloque_b);
			(*coste_b)++;
		}
	}
}

void	ft_mover(t_bloques **bloque_a, t_bloques **bloque_b,
			int coste_a, int coste_b)
{
	if (coste_a < 0 && coste_b < 0)
		ft_rotar_reverso_ambos(bloque_a, bloque_b, &coste_a, &coste_b);
	else if (coste_a > 0 && coste_b > 0)
		ft_rotar_ambos(bloque_a, bloque_b, &coste_a, &coste_b);
	ft_rotar_a(bloque_a, &coste_a);
	ft_rotar_b(bloque_b, &coste_b);
	ft_pa(bloque_a, bloque_b);
}
