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
	t_algo algo;

	lem = ft_malloc_protect(sizeof(t_lem_00));
	algo = &lem->algo;
	ft_bzero(lem, sizeof(t_lem_00));
	lem->data = lem_read_line();
	init_cache(&lem->algo.cache, &lem->data);
	(void)1;
	generate_map(&algo->map,  lem->data.room->length);
	set_tunnel(&lem->data, &algo->map);
	ft_memcpy(algo->map.work, algo->map.base, algo->map.size);
	print_map(algo->map.work, algo->map.y);
	algo->cache.current_room = lem->data.start_nb;
	return (lem);
}

void     free_lem(t_lem lem)
{
    t_algo algo;
	t_data data;

	algo = &lem->algo;
	data = &lem->data;

	destroy_map(&lem->algo.map);
	destroy_dll_func(&data->room, &destroy_room);
	destroy_dll_func(&data->tunnel, &destroy_tunnel);
	free(lem);
}