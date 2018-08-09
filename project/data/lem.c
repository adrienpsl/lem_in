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

extern t_debug_struct DEBUG;

void set_up_algo(t_algo algo, t_data data)
{
	t_map map;

	init_cache(&algo->cache, data);
	map = &algo->map;
	generate_map(map,  data->room->length);
	set_tunnel(data, map);

//	print_map(map->start, map->line);
}

t_lem new_lem()
{
	t_lem lem;

	lem = ft_0_new_memory(sizeof(t_lem_00));
//	set_up_algo(&lem->algo, lem->data);

	return (lem);
}

void     free_lem(t_lem lem)
{
	destroy_map(&lem->algo.map);
	if (lem->data)
	{
		destroy_dll_func(&lem->data->room, &destroy_room);
		destroy_dll_func(&lem->data->tunnel, &destroy_tunnel);
	}
	free(lem);
}