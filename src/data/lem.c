/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:02:33 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:03:27 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

void	kill_algo(t_algo algo)
{
	destroy_map(algo->map);
	destroy_dll(&algo->cache.all_path);
	destroy_dll_func(&algo->cache.valid_path, dll_l_notfree_content);
	free(algo);
}

void	free_lem(t_lem lem)
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
