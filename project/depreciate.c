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

#include "all_includes.h"

int is_not_this_room(t_dll_l link, void *name_end_room)
{
	t_path path;

	path = link->content;
	path = path->prev;
	if (path->room == *(int *) name_end_room)
		return (FALSE);
	return (TRUE);
}

void keep_good_path(t_dll closed_path, t_dll good_path)
{
	t_path cur_room;
	t_dll_l current_path_link;
	t_dll_l tmp_link;
	char a;
	char b;

	// faire une new rev list pour chaque maillon
	current_path_link = dll_drop_link(closed_path, closed_path->top);
	cur_room = current_path_link->content;
	cur_room = cur_room->prev;
	a = cur_room->room + 'A';

	while (dll_find_and_drop(closed_path, is_not_this_room, &cur_room->room,
							 &tmp_link))
	{
		b = ((t_path)tmp_link->content)->prev->room + 'A';
		dll_add(tmp_link, good_path);
	}
}

void print_tab(t_vt tab_ptr)
{
	size_t i;
	void **tab;
	t_path path;

	tab = tab_ptr->tab;
	i = 0;
	while (i < tab_ptr->size)
	{
		path = tab[i];
		print_path(path);
		++i;
	}
}


t_vt build_tab(t_dll list_ptr)
{
	t_vt tab_ptr;
	void **tab;
	t_dll list;
	t_dll_l link_list_ptr;
	size_t i;

	t_path path;

	tab_ptr = new_void_tab(list_ptr->length);
	tab = tab_ptr->tab;
	i = 0;
	link_list_ptr = list_ptr->top;
	while (link_list_ptr)
	{
		list = link_list_ptr->content;
		path = list->top->next->content;
		tab[i] = path;

		i++;
		link_list_ptr = link_list_ptr->next;
	}
	print_tab(tab_ptr);
	return (tab_ptr);
}