/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:34 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

static int	dll_is_link_reseached(t_dll_l link, void *link_wanted)
{
	if (link == link_wanted)
		return (TRUE);
	return (FALSE);
}

static int	find_and_delete(t_dll list, t_dll_l link)
{
	t_dll_l prev_link;
	t_dll_l next_link;

	link = dll_find(list, dll_is_link_reseached, link);
	if (link == NULL)
		return (FALSE);
	next_link = link->next;
	prev_link = link->prev;
	next_link->prev = prev_link;
	prev_link->next = next_link;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (TRUE);
}

int			dll_delete_link(t_dll list, t_dll_l link)
{
	t_dll_l tmp_link;

	tmp_link = NULL;
	if (list->length == 0)
		return (FALSE);
	else if (list->length == 1)
		tmp_link = dll_drop_list_one(list);
	else if (link == list->top)
		tmp_link = dll_drop_top(list);
	else if (link == list->end)
		tmp_link = dll_drop_end(list);
	if (tmp_link)
		return (TRUE);
	return (find_and_delete(list, link));
}
