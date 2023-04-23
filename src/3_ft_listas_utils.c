/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listas_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 08:57:02 by dramirez          #+#    #+#             */
/*   Updated: 2023/03/04 08:57:02 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*ft_nuevalista
*	Creamos la nueva lista reservando memoria y 
*	ponemos a 0 todos los parámetros*/
t_bloques	*ft_nuevalista(int nuevo_nodo)
{
	t_bloques	*nuevalst;

	nuevalst = malloc (sizeof(t_bloques));
	if (!nuevalst)
		return (NULL);
	nuevalst->numero = nuevo_nodo;
	nuevalst->indice = 0;
	nuevalst->posicion = -1;
	nuevalst->posicion_objetivo = -1;
	nuevalst->coste_a = -1;
	nuevalst->coste_b = -1;
	nuevalst->siguiente = NULL;
	return (nuevalst);
}

/*	Metemos en la lista del stack a los int metidos
*	bloque_a: Metemos los datos en el bloque a
*	argumento: argumento a cargar
*	numero: numero que se inserta
*	Inicializamos el Bloque A: fila 45
*	Si solo hay un argumento creamos la nueva lista: fila 56
*	Si hay más de un arg.: lo añadimos al final de la nueva lista: fila 59*/
t_bloques	*ft_datosenlista_int(int argc, char **argv)
{
	t_bloques	*cabeza;
	int			argumento;
	long int	numero;

	cabeza = NULL;
	argumento = 1;
	numero = 0;
	while (argumento < argc)
	{
		numero = ft_atoi(argv[argumento]);
		if (numero < INT_MIN || numero > INT_MAX)
			ft_error(&cabeza, NULL);
		if (argumento == 1)
			cabeza = ft_nuevalista((int)numero);
		else
			ft_lstadd_back_ps(&cabeza, ft_nuevalista((int)numero));
		argumento++;
	}
	return (cabeza);
}

/*Metemos en la lista del Stack A los int metidos
*	Igual que el caso anterior*/
t_bloques	*ft_datosenlista_num(int argc, char **argv)
{
	t_bloques	*bloque_a;
	int			argumento;
	long int	numero;

	bloque_a = NULL;
	argumento = 0;
	numero = 0;
	while (argumento < argc)
	{
		numero = ft_atoi(argv[argumento]);
		if (numero < INT_MIN || numero > INT_MAX)
			ft_error(&bloque_a, NULL);
		if (argumento == 0)
			bloque_a = ft_nuevalista((int)numero);
		else
			ft_lstadd_back_ps(&bloque_a, ft_nuevalista((int)numero));
		argumento++;
	}
	return (bloque_a);
}

/* ft_indices:
*	Asigna un índice a cada valor de la pila a. Comparamos y chequeamos
*	índices en lugar de los propios valores que pueden ser o no consecutivos.
*		Ejemplo:		-3	 0	 9	 2
*		Índices:		[1]	[2]	[4]	[3]
*	Los índices se asignan del menor (1) al mayor(longitud_pila)
*/
void	ft_indices(t_bloques *pila_a, int longitud_pila)
{
	t_bloques	*puntero;
	int			num;
	t_bloques	*mas_alto;

	while (longitud_pila > 0)
	{
		puntero = pila_a;
		num = INT_MIN;
		mas_alto = NULL;
		while (puntero)
		{
			if (puntero->numero == INT_MIN && puntero->indice == 0)
				puntero->indice = 1;
			else if (puntero->numero > num && puntero->indice == 0)
			{
				num = puntero->numero;
				mas_alto = puntero;
				puntero = pila_a;
			}
			puntero = puntero->siguiente;
		}
		if (mas_alto != NULL)
			mas_alto->indice = longitud_pila;
		longitud_pila--;
	}
}

t_bloques	*ft_lstpenultimo(t_bloques *pilas)
{
	while (pilas && pilas->siguiente && pilas->siguiente->siguiente != NULL)
		pilas = pilas->siguiente;
	return (pilas);
}
