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

t_finder new_finder(t_data data, int new_room_start, t_map map, t_cache cache)
{
	t_finder finder;

	finder = ft_0_new_memory(sizeof(t_finder_00));
	finder->close_path = cache->close_path;
	finder->new_path = new_dll();
	finder->all_path = cache->all_path;
	finder->working_path = new_dll();
	finder->end_room = data->end_room;
	finder->start_room = new_room_start;
	finder->taken_room = ft_0_new_memory(sizeof(char) * map->line);
	return (finder);
}

void destroy_finder(t_finder finder)
{
	free(finder->taken_room);
	destroy_dll_func(&finder->working_path, dll_l_notfree_content);
	destroy_dll_func(&finder->new_path, dll_l_notfree_content);
	free(finder);
}

void print_finder_link(t_dll_l finder_link)
{
	t_finder finder;

	finder = finder_link->content;

	if (finder->working_path)
	{
		printf("working finder \n");
		dll_func(finder->working_path, print_path_dll);
	}
}

void print_finder(t_dll finder_list)
{
	t_finder finder;

	dll_func(finder_list, print_finder_link);
	if (finder_list->top)
	{
		finder = finder_list->top->content;
		if (finder->working_path)
		{
			printf("closed finder \n");
			dll_func(finder->close_path, print_path_dll);
		}
	}
	printf("------------------------------------------ \n");
}