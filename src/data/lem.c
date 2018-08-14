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

#include "../includes/all_includes.h"


void kill_algo(t_algo algo)
{
	destroy_map(algo->map);
	destroy_dll(&algo->cache.all_path);
	destroy_dll_func(&algo->cache.valid_path, dll_l_notfree_content);
//	destroy_dll(&algo->cache.valid_path);
	free(algo);
}

void free_lem(t_lem lem)
{
	if (lem->data != NULL)
	{
		destroy_dll_func(&lem->data->room, &destroy_room);
		destroy_dll_func(&lem->data->tunnel, &destroy_tunnel);
		free(lem->data);
	}
	if (lem->algo != NULL)
	{
		kill_algo(lem->algo);
	}
	free(lem);
}