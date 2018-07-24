/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../all_includes.h"

/*------------------------------------*\

\*------------------------------------*/


// function pour avancer dans les path + quand fourmis arrive a passer 
// dans end, je la print


/*------------------------------------*\
    print la fourmis si elle est dans la salle end et la supprime

\*------------------------------------*/

/*------------------------------------*\
	f pour faire avancer toute les fourmis et print celle qui sont ok
 	boucle sur chaque chemin et avance les fourmis d'un a chaque fois
\*------------------------------------*/
//void move_all_f(t_move move)
//{
//
//}

int is_free(t_move move, size_t nb_path, size_t room)
{
	t_dll_l link;

	link = move->tab[nb_path]->list_path->top;
	while (room)
	{
		link = link->next;
		--room;
	}
	return (
	 ((t_path) link->content)->is_full ? FALSE : TRUE);
}

/*------------------------------------*\
    dois check si j'ai la fourmis est a la fin pour empty
\*------------------------------------*/

int add_f(t_move move, size_t nb_path, size_t room, int f_nb)
{
	t_dll_l link;
	t_path path;
	int bn;
	int zize;

	link = move->tab[nb_path]->list_path->top;
	zize = move->tab[nb_path]->size - 2;
	bn =  move->nb_fourmis - f_nb;
	if (move->nb_fourmis < f_nb)
		return TRUE;
	if (nb_path > 0 && bn < zize)
		return FALSE;
	while (room)
	{
		link = link->next;
		--room;
	}
	path = link->content;
	printf("F%d-%s ", f_nb, path->name_room);
	if (path->room != move->end_room)
		path->is_full = f_nb;
	return (TRUE);
}
/*------------------------------------*\
    metre fourmis dans salle si
    boucle sur les path et si le path est plus grand que le nb de fourmis
    restant, je passe le tour
\*------------------------------------*/
int put_f_all_start(t_move move)
{
	size_t path;
	size_t *F;
	static size_t f = 1;

	path = 0;
	F = &f;
	while (path < move->size_tab)
	{
		if (move->nb_fourmis > 0 &&
			is_free(move, path, 1) == TRUE)
		{
			if (add_f(move, path, 1, f) == TRUE)
				++f;
		}
		++path;
	}
	return (f < (size_t) move->nb_fourmis ? TRUE : FALSE);
}

/*------------------------------------*\
    avancer tout les fourmis ?
    reccursif, tant que le link a une fourmis je decalle d'un
\*------------------------------------*/
int recursif_all_f(t_dll_l link, int new_f, int end_room)
{
	t_path path;
	int i;

	i = 0;
	path = link->content;
	if (link->next)
	{
		i = recursif_all_f(link->next, path->is_full, end_room);
	}
	path->is_full = 0;
	if (new_f)
	{
		i = 1;
		printf("F%d-%s ", new_f, path->name_room);
		path->is_full = new_f != end_room ? new_f : 0;
	}
	return (i);
}

int move_all_f(t_move move)
{
	size_t i;
	int res;

	i = 0;
	while (i < move->size_tab)
	{
		res = recursif_all_f(move->tab[i]->list_path->top, 0, move->end_room) ?
			  1 : 0;
		++i;
	}
	return (res);
}

/*------------------------------------*\
    manage le movement des fourmis
\*------------------------------------*/
void manage_move(t_move move)
{
	(void) move;

	while (put_f_all_start(move))
	{
		printf("\n-------------------- \n\n");
		move_all_f(move);
	}
	//	printf("\n-------------------- \n\n");
	printf("\n-------------------- \n\n");

	//	move_all_f(move);
	//	printf("\n-------------------- \n\n");

	while (move_all_f(move))
	{
		put_f_all_start(move);
		printf("\n-------------------- \n\n");
	}
}