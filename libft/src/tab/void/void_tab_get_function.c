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

#include "../../../ft_library_header.h"

void	vt_get_dll(t_vt tab_ptr, t_dll list)
{
	t_dll_l	cur_link;
	void	**tab;

	cur_link = list->top;
	tab = tab_ptr->tab;
	while (cur_link)
	{
		tab = cur_link->content;
		tab++;
		cur_link = cur_link->next;
	}
}

void	vt_get_dll_func(t_vt v_tab, t_dll list, void *(*func)(t_dll_l, void*),
	void *void_ptr)
{
	t_dll_l	cur_link;
	void	**tab;

	cur_link = list->top;
	tab = v_tab->tab;
	while (cur_link)
	{
		*tab = func(cur_link, void_ptr);
		tab++;
	}
}
