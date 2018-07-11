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

void init_cache(t_cache cache, t_data data)
{
	cache->all_path = new_dll();
	cache->close_path = new_dll();
	cache->end_room = data->end_room;
}

void destroy_cache(t_cache cache)
{
	destroy_dll_func(&cache->close_path, dll_l_notfree_content);
	// destroy la liste des cache
	//	destroy_dll_func(&cache->working_path, dll_l_notfree_content);
	destroy_dll(&cache->all_path);
}