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

void generate_map(t_map map, int y)
{
	map->y = y;
	map->size = sizeof(char) * map->y * map->y;
	map->base = ft_malloc_protect(map->size);
	map->work = ft_malloc_protect(map->size);
	ft_bzero(map->base, map->size * 2 + sizeof(char) * map->y);

}

void destroy_map(t_map map)
{
	free(map->base);
	free(map->work);
}
