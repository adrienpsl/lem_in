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

void	vt_print_func(t_vt tab_ptr, int (*func)(void *, void *), void *ptr)
{
	size_t	i;
	void	**tab;

	i = 0;
	tab = tab_ptr->tab;
	while (i < tab_ptr->size)
	{
		func(tab[i], ptr);
		++i;
	}
}
