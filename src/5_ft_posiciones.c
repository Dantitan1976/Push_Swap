/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:37:06 by dramirez          #+#    #+#             */
/*   Updated: 2023/02/26 23:37:06 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* asignar_posicion:
*	Asigna una posición a cada elemento del bloque, de arriba a abajo en orden
*	ascendente
*	Ejemplo:
*		valor:		 3	 0	 9	 1
*		indice:		[3]	[1]	[4]	[2]
*		posicion:	<0>	<1>	<2>	<3>
*	Con esto calculamos el coste de mover un número a una posicion
*	Si estamos en el bloque b, no costará nada mover el primer elemento al bloque a
*	Sin embargo, si queremos empujar el valor más alto [9], que está en la tercera
*	posicion, costaría 2 movimientos extra para llevar el 9 a la primera posición
*	del bloque b antes de empujarlo al bloque a.
*/
static void	asignar_posicion(t_bloques **bloque)
{
	t_bloques	*temporal;
	int			numero;

	temporal = *bloque;
	numero = 0;
	while (temporal)
	{
		temporal->posicion = numero;
		temporal = temporal->siguiente;
		numero++;
	}
}

/* posicion_indice_masbajo
*	Obtenemos la posicion actual del elemento con el índice
*	más bajo dentro del bloque.
*		valor:		 3	 0	 9	 1
*		indice:		[3]	[1]	[4]	[2]
*		posicion:	<0>	<1>	<2>	<3>
*/
int	pos_indice_masbajo(t_bloques **bloque)
{
	t_bloques	*temporal;
	int			indice_masbajo;
	int			pos_indicemasbajo;

	temporal = *bloque;
	indice_masbajo = INT_MAX;
	asignar_posicion(bloque);
	pos_indicemasbajo = temporal->posicion;
	while (temporal)
	{
		if (temporal->indice < indice_masbajo)
		{
			indice_masbajo = temporal->indice;
			pos_indicemasbajo = temporal->posicion;
		}
		temporal = temporal->siguiente;
	}
	return (pos_indicemasbajo);
}

/*	posicion_objetivo:
*	Toma la mejor posición en el bloque A para el índice
*	de un elemento del bloque B. Primero chequea si el indice
*	del elemento del bloque B se puede ubicar entre algún
*	elemento del bloque A, mirando si hay algún elemento del
*	bloque A con un número de índice superior. Si no, encuentra el
*	elemento en A con el índice más bajo y lo asigna como posición objetivo.
*		Ejemplo:
*	posicion_objetivo arranca en INT_MAX
*	Indice en B: 3
*	A contiene índices: 9 4 2 1 0
*	9 > 3 && 9 < INT_MAX 	: actualiza la posicion objetivo de 9
*	4 > 3 && 4 < 9 			: actualiza la posicion objetivo de 4
*	2 < 3 && 2 < 4			: no se actualiza la posicion objetivo de 2
*	De esta manera la posición objetivo tiene que ser el índice #4
*	ya que es el índice más cercano.
*		Example:
*	posicion_objetivo arranca en INT_MAX
*	Índice en B: 20
*	A contiene los índices: 16 4 3
*	16 < 20	: no se actualiza! La posicion objetivo está al final.
*	4  < 20	: no se actualiza! La posicion objetivo está al final.
*	3  < 20	: no se actualiza! La posicion objetivo está al final.
*	... target_pos stays at INT MAX, need to switch strategies.
*	16 < 20	: Al pasar el valor a A, actualizamos la posición objetivo de 20
*	4  < 20	: Al pasar el valor a A, actualizamos la posición objetivo de 4
*	3  < 20	: Al pasar el valor a A, actualizamos la posición objetivo de 3
*	So target_pos needs to be the position of index 3, since that is
*	the "end" of the stack.
*/
static int	posicion_objetivo(t_bloques **bloque_a, int indice_bloqueb,
				int posicion_objetivo, int indice_objetivo)
{
	t_bloques	*temp_a;

	temp_a = *bloque_a;
	while (temp_a)
	{
		if (temp_a->indice > indice_bloqueb && temp_a->indice < indice_objetivo)
		{
			indice_objetivo = temp_a->indice;
			posicion_objetivo = temp_a->posicion;
		}
		temp_a = temp_a->siguiente;
	}
	if (indice_objetivo != INT_MAX)
		return (posicion_objetivo);
	temp_a = *bloque_a;
	while (temp_a)
	{
		if (temp_a->indice < indice_objetivo)
		{
			indice_objetivo = temp_a->indice;
			posicion_objetivo = temp_a->posicion;
		}
		temp_a = temp_a->siguiente;
	}
	return (posicion_objetivo);
}

void	ft_asigna_pos_obj(t_bloques **bloque_a, t_bloques **bloque_b)
{
	t_bloques	*temp_b;
	int			pos_obj;

	temp_b = *bloque_b;
	asignar_posicion(bloque_a);
	asignar_posicion(bloque_b);
	pos_obj = 0;
	while (temp_b)
	{
		pos_obj = posicion_objetivo(bloque_a, temp_b->indice, pos_obj, INT_MAX);
		temp_b->posicion_objetivo = pos_obj;
		temp_b = temp_b->siguiente;
	}	
}
