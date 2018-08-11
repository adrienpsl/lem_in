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

#include "../includes/all_includes.h"

t_dll_l dll_ptr_at_index(t_dll room_list, size_t i)
{
	t_dll_l link;

	link = room_list->top;
	while (i)
	{
		link = link->next;
		--i;
	}
	return (link);
}

// generer et rement dans l'ordre chaque path
t_dll good_list(t_path path, t_dll room_list)
{
	t_dll path_list;
	t_dll_l link_room;
	t_dll_l link;

	path_list = new_dll();
	while (path)
	{
		link_room = dll_ptr_at_index(room_list, path->room);
		path->name_room = ((t_room) link_room->content)->name;
		link = new_dll_l(path, sizeof(t_path_00));
		dll_add_at_index(link, path_list, 0);
		path = path->prev;
	}
	return (path_list);
}

t_real_path
new_real_path(t_path path, t_dll room_list)
{
	t_real_path real;

	real = ft_0_new_memory(sizeof(t_real_path_00));
	real->size = path->size;
	real->list_path = good_list(path, room_list);
	dll_func(real->list_path, print_path_link);

	return (real);
}

// je remplit le tab avec les chemins correct les real path
void
fill_tab(t_b_path best_path, t_finder finder, t_real_path *real_tab,
 t_dll room_list)
{
	t_dll_l link;
	size_t i;
	int tab_nb;

	i = 0;
	tab_nb = 0;
	link = finder->valid_path->top;
	while (link)
	{
		if (best_path->tab[i])
		{
			real_tab[tab_nb] = new_real_path(link->content, room_list);
			++tab_nb;
		}
		++i;
		link = link->next;
	}
}

t_move new_move(t_data data, t_b_path best_path, t_finder finder)
{
	t_move move;

	move = ft_0_new_memory(sizeof(t_move_00));
	move->nb_fourmis = data->nb_fourmis;
	move->data = data;
	// limiter la taille des real path au nombre max de passage possible
	// quand je les cherche je les comparent dierctement pour savoir s'il sont diffenent ?
	move->tab = ft_0_new_memory(sizeof(t_real_path_00) * (best_path->nb + 1));
	move->tab[best_path->nb] = NULL;
	move->size_tab = best_path->nb;
	move->end_room = data->end_room;
	fill_tab(best_path, finder, move->tab, data->room);

	return (move);
}