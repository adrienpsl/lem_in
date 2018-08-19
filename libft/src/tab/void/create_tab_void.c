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

t_vt	new_void_tab(size_t size_tab)
{
	t_vt tab;

	tab = ft_malloc_protect(sizeof(t_vt_00));
	tab->tab = ft_malloc_protect(sizeof(void **) * size_tab);
	tab->size = size_tab;
	return (tab);
}

void	destruct_v_tab(t_vt *tab_ptr)
{
	t_vt tab;

	tab = *tab_ptr;
	free(tab->tab);
	free(tab);
	tab = NULL;
}
