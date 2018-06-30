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

size_t fill_path(t_cache cache, t_map map)
{
	t_dll_l current_work;
	int res;

	current_work = cache->working_path->top;
	while (current_work)
	{
		split_path(map, cache, current_work->content, &res);
		current_work = current_work->next;
		if (res == 0)
			dll_drop_link(cache->working_path, current_work->prev);
	}
	//	dll_func(cache->working_path, print_path_dll);
	clean_woking(cache);
	return (cache->working_path->length);
}

void     get_all_path(t_cache cache, t_map map)
{
	while (fill_path(cache, map))
	{}
}