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

t_finder new_finder(t_data data, int new_room_start, t_map map)
{
		t_finder finder;

		finder = ft_0_new_memory(sizeof(t_finder_00));
		finder->close_path = new_dll();
		finder->new_path = new_dll();
		finder->all_path = new_dll();
		finder->working_path = new_dll();
		finder->end_room = data->end_room;
		finder->start_room = new_room_start;
		finder->taken_room = ft_0_new_memory(sizeof(char) * map->line);
		return (finder);
}


