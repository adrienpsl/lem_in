/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_finder_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:07:02 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:08:09 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

t_finder	new_finder(t_data data, int new_room_start,
		t_map map, t_cache cache)
{
	t_finder	finder;

	finder = ft_0_new_memory(sizeof(t_finder_00));
	finder->new_path = new_dll();
	finder->working_path = new_dll();
	finder->valid_path = cache->valid_path;
	finder->all_path = cache->all_path;
	finder->end_room = data->end_room;
	finder->start_room = new_room_start;
	finder->taken_room = ft_0_new_memory(sizeof(char) * map->line);
	return (finder);
}
