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

//void set_line_all_1(t_map map)
//{
//	ft_memset(map->line, )
//}

// filtre binaire pour la ligne de la map
/*
 * le nb de la room donnee == sa place dans le tab
 * */
void binarie_line(t_map map,/* t_cache cache,*/ int current_room)
{
	t_tab_room map_line;
	size_t i;

	map_line = map->work + current_room;
	i = 0;
	while (i < map->y)
	{
		if (map_line[i].link == TRUE)
		{
			if (map_line[i].path == 0 && map_line[i].taken == FALSE)
				// j'ajoute a new path un ptr sur cette room
				(void)1; // je genere un path pour chaque lien valide
		}
	}
}



// filtre binaire pour tout les el de la map, convertie en path

// donner le path a tous les elements de la map

