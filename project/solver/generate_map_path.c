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

void add_all_path(char *map, t_dll_l path_link, size_t line)
{
	t_path path;

	path = path_link->content;
	path = path->prev;
	while (path->prev)
	{
		map[path->room + line] = 1;
		path = path->prev;
	}
}

/*------------------------------------*\
    mets dans une map tout les path possibles
\*------------------------------------*/
void generate_path_map(t_dll room, t_dll path_lst, t_map map)
{

	t_dll_l link;
	size_t i;

	link = path_lst->top;
	map->line = room->length;
	map->col = path_lst->length;
	i = 0;
	map->start = ft_0_new_memory(sizeof(char) * map->line * map->col);
	while (link)
	{
		add_all_path(map->start, link, i * map->line);
		link = link->next;
		++i;
	}
	print_path_map(map->start, room->length, map->col);
}