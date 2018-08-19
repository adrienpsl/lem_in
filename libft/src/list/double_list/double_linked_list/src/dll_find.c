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

t_dll_l	dll_find(t_dll list, int (*func)(t_dll_l, void *), void *ptr)
{
	t_dll_l link;

	if (list == NULL)
		return (NULL);
	link = list->top;
	while (link)
	{
		if (func(link, ptr) == TRUE)
			return (link);
		link = link->next;
	}
	return (NULL);
}

t_dll_l	dll_find_index(t_dll list, int (*func)(t_dll_l, void *), void *ptr,
	size_t *index_ptr)
{
	t_dll_l	link;
	size_t	index;

	if (list == NULL)
		return (NULL);
	index = 0;
	link = list->top;
	while (link)
	{
		if (func(link, ptr) == TRUE)
		{
			*index_ptr = index;
			return (link);
		}
		link = link->next;
		++index;
	}
	return (NULL);
}

t_dll_l	dll_index_found(t_dll list, t_dll_l link, size_t index)
{
	t_dll_l prev_link;
	t_dll_l next_link;

	if (list->length == 1)
		return (dll_drop_list_one(list));
	else if (index == 1)
		return (dll_drop_top(list));
	else if (index >= list->length)
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

int		dll_find_and_drop(t_dll list, int (*func)(t_dll_l, void *), void *ptr,
	t_dll_l *link_out)
{
	t_dll_l	link;
	size_t	index;

	index = 0;
	link = list->top;
	if (link == NULL || list == NULL)
		return (FALSE);
	while (link)
	{
		++index;
		if (func(link, ptr) == TRUE)
		{
			*link_out = dll_index_found(list, link, index);
			return (TRUE);
		}
		link = link->next;
	}
	return (FALSE);
}

int		dllwhere_find_and_drop(t_dll list, int (*func)(t_dll_l, void *),
	void *ptr,
	t_dll_l *link_out)
{
	t_dll_l	link;
	size_t	index;

	index = 0;
	link = list->where;
	if (link == NULL || list == NULL)
		return (FALSE);
	while (link)
	{
		++index;
		if (func(link, ptr) == TRUE)
		{
			*link_out = dll_index_found(list, link, index);
			return (TRUE);
		}
		link = link->next;
	}
	return (FALSE);
}
