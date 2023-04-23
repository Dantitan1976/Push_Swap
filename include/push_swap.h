/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:47:33 by dramirez          #+#    #+#             */
/*   Updated: 2023/02/22 20:39:13 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <limits.h>
/*	*siguiente = puntero al siguiente nodo
*	numero = numero a ordenar
*	indice = indice del número en la lista
*	posicion = posición del número en la lista
*	posicion_objetivo = posición donde vamos a insertar el número a ordenar
*	coste_a = coste de mover los elementos al Stack A
*	coste_b = coste de mover los elementos en el Stack B*/
typedef struct s_bloques//Estructura de los bloques a y b
{
	struct s_bloques	*siguiente;
	int					numero;
	int					indice;
	int					posicion;
	int					posicion_objetivo;
	int					coste_a;
	int					coste_b;
}	t_bloques;

//1_ft_check_int.c
int			ft_num_abs(int numero);
char		ft_check_num(char *str);
long int	ft_check_int(char *str);
char		ft_check_dobles_int(int argc, char **argv);
void		ft_check_args_int(int argc, char **argv);
//2_ft_check_num.c
int			ft_numseparad(char *str, char separador);
//char		ft_check_num(char *str);
char		ft_check_dobles(int argc, char **argv);
//void		ft_putstr_fd(char *s, int fd);
//void		ft_error(void);
void		ft_check_args(int argc, char **argv);
//3_ft_listas_utils.c
t_bloques	*ft_nuevalista(int nuevo_nodo);
t_bloques	*ft_datosenlista_int(int argc, char **argv);
t_bloques	*ft_datosenlista_num(int argc, char **argv);
void		ft_indices(t_bloques *pila_a, int longitud_pila);
t_bloques	*ft_lstpenultimo(t_bloques *pilas);
//3_ft_listas_utils2.c
void		ft_error(t_bloques **stack_a, t_bloques **stack_b);
void		ft_liberarbloques(t_bloques **bloques);
void		ft_lstadd_back_ps(t_bloques **lst, t_bloques *new);
t_bloques	*ft_lstlast_ps(t_bloques *lst);
int			ft_lstsize_ps(t_bloques *lst);
//4_ft_push.c
void		ft_pa(t_bloques **bloque_a, t_bloques **bloque_b);
void		ft_pb(t_bloques **bloque_a, t_bloques **bloque_b);
//4_ft_rotar_reverso.c
void		ft_rra(t_bloques **bloque_a);
void		ft_rrb(t_bloques **bloque_b);
void		ft_rrr(t_bloques **bloque_a, t_bloques **bloque_b);
//4_ft_rotar.c
void		ft_ra(t_bloques **bloque_a);
void		ft_rb(t_bloques **bloque_b);
void		ft_rr(t_bloques **bloque_a, t_bloques **bloque_b);
//4_ft_swap.c
void		ft_sa(t_bloques **bloque_a);
void		ft_sb(t_bloques **bloque_b);
void		ft_ss(t_bloques **bloque_a, t_bloques **bloque_b);
//5_ft_mover.c
void		ft_mover(t_bloques **bloque_a, t_bloques **bloque_b,
				int coste_a, int coste_b);
//5_ft_posiciones_coste.c
void		ft_coste_ba(t_bloques **bloque_a, t_bloques **bloque_b);
void		ft_mov_mas_efic(t_bloques **bloque_a, t_bloques **bloque_b);
//5_ft_posiciones.c
int			pos_indice_masbajo(t_bloques **bloque);
void		ft_asigna_pos_obj(t_bloques **bloque_a, t_bloques **bloque_b);
//6_ft_ordenar_3.c
void		ft_ordenar_3(t_bloques **bloque);
//6_ft_ordenar_3mas.c
void		ft_ordenar_3mas(t_bloques **bloque_a, t_bloques **bloque_b);
//6_ft_ordenar_utils.c
//int			*ft_ordenar_array(int *numeros, int longitud);
int			ft_check_orden(t_bloques *bloque);
//main.c
int			main(int argc, char **argv);
void		ft_imprimirlista(t_bloques *bloque_a);

#endif
