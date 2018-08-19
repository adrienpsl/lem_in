/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:23:40 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

t_dll_l	dll_drop_top(t_dll list)
{
	t_dll_l link;
	t_dll_l new_top;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->top;
	new_top = list->top->next;
	list->top = new_top;
	new_top->prev = NULL;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}

t_dll_l	dll_drop_end(t_dll list)
{
	t_dll_l link;
	t_dll_l new_end;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->end;
	new_end = list->end->prev;
	list->end = new_end;
	new_end->next = NULL;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}

t_dll_l	dll_drop_list_one(t_dll list)
{
	t_dll_l link;

	link = list->top;
	list->top = NULL;
	list->end = NULL;
	list->length -= 1;
	return (link);
}

t_dll_l	dll_drop_link(t_dll list, t_dll_l link)
{
	t_dll_l prev_link;
	t_dll_l next_link;

	if (link == NULL || list == NULL)
		return (NULL);
	if (list->length == 1)
		return (dll_drop_list_one(list));
	else if (link == list->top)
		return (dll_drop_top(list));
	else if (link == list->end)
		return (dll_drop_end(list));
	else
	{
		next_link = link->next;
		prev_link = link->prev;
		next_link->prev = prev_link;
		prev_link->next = next_link;
		reset_ptr_dll_l(link);
		list->length -= 1;
		return (link);
	}
}
