/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../ft_library_header.h"

void	dll_func_lim(t_dll lst, int lim, void (*func)(t_dll_l))
{
	t_dll_l link;

	link = lst->top;
	while (lim)
	{
		func(link);
		link = link->next;
		--lim;
	}
	ft_printf(" \n");
}

void	dll_func(t_dll lst, void (*func)(void *))
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		func(link->content);
		link = link->next;
	}
}

void	dll_func_where(t_dll lst, void (*func)(t_dll_l))
{
	t_dll_l link;

	link = lst->where;
	while (link)
	{
		func(link);
		link = link->next;
	}
	ft_printf("\n");
}

int		dll_func_ret(t_dll lst, int (*func)(t_dll_l))
{
	t_dll_l link;

	link = lst->top;
	while (link)
	{
		if (func(link) == TRUE)
			return (TRUE);
		link = link->next;
	}
	return (FALSE);
}
