/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_drop_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:33 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

int	dll_index_link(t_dll_l link_searched, t_dll list, size_t *index_ptr)
{
	size_t	index;
	t_dll_l	current_link;

	index = 0;
	current_link = list->top;
	while (current_link)
	{
		if (current_link == link_searched)
		{
			*index_ptr = index;
			return (TRUE);
		}
		current_link = current_link->next;
		++index;
	}
	return (FALSE);
}

int	dll_index_link_func(t_dll list, int (*func)(t_dll_l, void*), void *ptr,
	size_t *index_ptr)
{
	size_t	index;
	t_dll_l	current_link;

	index = 0;
	current_link = list->top;
	while (current_link)
	{
		if (func(current_link, ptr) == TRUE)
		{
			*index_ptr = index;
			return (TRUE);
		}
		current_link = current_link->next;
		++index;
	}
	return (FALSE);
}
