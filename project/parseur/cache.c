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
	cache->new_path = new_dll();
	cache->room = data->room;
	cache->working_path = new_dll();
	cache->is_full = ft_malloc_protect(sizeof(int) * cache->room->length);
	ft_bzero(cache->is_full, sizeof(int) * cache->room->length);
}

/*
**    va set la peremiere salle comme path et initialisser les donnees
**    correctement pour lancer l'algo
*/
void set_up()
{
}

void clean_woking(t_cache cache)
{
	destroy_dll_func(&cache->working_path, dll_l_notfree_content);
	cache->working_path = cache->new_path;
	cache->new_path = new_dll();
}