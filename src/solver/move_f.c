/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 16:30:35 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int			is_free(t_move move, size_t nb_path)
{
	t_dll_l		link;

	link = move->tab[nb_path]->list_path->top->next;
	return (((t_path)link->content)->is_full ? FALSE : TRUE);
}

int			add_f(t_move move, size_t nb_path, int f_nb)
{
	t_path		path;
	int			path_more_longh_wait;
	int			size;

	path = move->tab[nb_path]->list_path->top->next->content;
	size = move->tab[nb_path]->size - 1;
	path_more_longh_wait = move->nb_fourmis - f_nb;
	if (nb_path > 0 && path_more_longh_wait < size)
		return (FALSE);
	ft_printf("L%d-%s ", f_nb, path->name_room);
	if (path->room != move->end_room)
		path->is_full = f_nb;
	return (TRUE);
}

/*
**metre fourmis dans salle si
**boucle sur les path et si le path est plus grand que le nb de fourmis
**restant, je passe le tour
*/

int			put_f_all_start(t_move move)
{
	size_t		path;
	static int	f = 0;

	path = 0;
	while (path < move->size_tab && move->nb_fourmis > f)
	{
		if (move->nb_fourmis > 0 && is_free(move, path) == TRUE)
		{
			if (add_f(move, path, f + 1) == TRUE)
				++f;
		}
		++path;
	}
	return (f < move->nb_fourmis ? TRUE : FALSE);
}

/*
** avancer tout les fourmis ?
** reccursif, tant que le link a une fourmis je decalle d'un
** parcoutd tout car il pourrait y avpir un trou dans le passage des f
*/

int			recursif_all_f(t_dll_l link, int new_f, int end_room)
{
	t_path		path;
	int			i;

	i = 0;
	path = link->content;
	if (link->next)
		i = recursif_all_f(link->next, path->is_full, end_room);
	path->is_full = 0;
	if (new_f)
	{
		i = 1;
		ft_printf("L%d-%s ", new_f, path->name_room);
		path->is_full = path->room != end_room ? new_f : 0;
	}
	return (i);
}

int			move_all_f(t_move move)
{
	size_t		i;
	int			res;

	i = 0;
	res = 0;
	while (i < move->size_tab)
	{
		res = recursif_all_f(move->tab[i]->list_path->top->next, 0,
				move->end_room) || res ? 1 : 0;
		++i;
	}
	return (res);
}

void		manage_move(t_move move)
{
	while (put_f_all_start(move))
	{
		ft_printf("\n");
		move_all_f(move);
	}
	ft_printf("\n");
	while (move_all_f(move))
		ft_printf("\n");
}
