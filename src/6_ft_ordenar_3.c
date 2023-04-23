/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ft_ordenar_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 23:07:26 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/19 23:07:26 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	ft_indice_mayor:
*	Devuelve el índice mayor de una pila o bloque
*/
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

/* ft_ordenar_3:
*	Ordena una pila de 3 números en 2 o menos movimientos. Se ordena por índices
*	en lugar de por valores. Ejemplo:
*		Valores:	 1	 8	 3
*		Índices:	[1]	[3]	[2]
*	Solución, 2 movimientos:
*	rra:
*		Valores:	 3	 1	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		Valores		 1	 3	 9
*		indexes:	[1]	[2]	[3]
*/
void	ft_ordenar_3(t_bloques **bloque)
{
	int	indice_mayor;

	if (ft_check_orden(*bloque))
		return ;
	indice_mayor = ft_indice_mayor(*bloque);
	if ((*bloque)->indice == indice_mayor)
		ft_ra(bloque);
	else if ((*bloque)->siguiente->indice == indice_mayor)
		ft_rra(bloque);
	if ((*bloque)->indice > (*bloque)->siguiente->indice)
		ft_sa(bloque);
}
