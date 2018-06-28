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

#include "../all_includes.h"

t_lem new_lem()
{
	t_lem lem;

	lem = ft_malloc_protect(sizeof(t_lem_00));
	ft_bzero(lem, sizeof(t_lem_00));
	return (lem);
}

void     free_lem(t_lem lem)
{
    t_algo algo;
	t_data data;

	algo = &lem->algo;
	data = &lem->data;

//	destroy_dll_func(&algo->working_path, &dll_l_notfree_content);
//	destroy_dll(&algo->all_path);
//	destroy_dll_func(&data->room, &destroy_room);
//	destroy_dll_func(&data->tunnel, &destroy_tunnel);
	free(lem);
}