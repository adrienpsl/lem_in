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

#include "../../includes/all_includes.h"

/*
**	**** VARIABLES
**	cur_path			>	list des room deja traverser par ce path
**	name_current_room	>	room linker avec la cur_room
**
**	**** RETURN
**	=> TRUE if the room if name_current_room is in cur_path
**
**	**** MAKING
**	Parcours tout les path precedent et compare a cur_room
**
**
*/
int is_already_taken2(char *tab_all_taken_room, int name_current_room)
{
	return (tab_all_taken_room[name_current_room]);
}

/*
**	**** VARIABLES
**	map			>	stock les connections entre toutes les rooms
**	finder		>	stock les data
**	cur_path	>	room dont je cherche les path
**
**	**** RETURN
**	=>//
**
**	**** MAKING
**	charge la ligne de la map de cur_path
**	tant que col < taille map
**		si room est connecter avec cur_room et pas deja parcouru
**			je genere un nouveau link,
**			je l'ajoute au new_path
*/
void split_path2(t_map map, t_finder finder, t_path cur_path, char *tab)
{
	char *map_line;
	t_dll_l path_link;
	size_t col;

	map_line = map->map + (cur_path->room * map->col);
	col = 0;
	while (col < map->col)
	{
		if (map_line[col] &&
			is_already_taken2(tab, col) == FALSE)
		{
			path_link = new_path_link(col,
									  cur_path,
									  finder->all_path,
									  cur_path->size + 1);
			tab[col] = TRUE;
			dll_add_at_index(path_link, finder->new_path,
							 finder->new_path->length);
		}
		++col;
	}
}

size_t split_all_path2(t_finder finder, t_map map, char *tab)
{
	t_dll_l cur_working_link;
	int i = 0;

	while (finder->working_path->length)
	{
		cur_working_link = finder->working_path->top;
		while (cur_working_link)
		{
			split_path2(map, finder, cur_working_link->content, tab);
			cur_working_link = cur_working_link->next;
		}
		//		deb_split(finder);
		clean_woking(finder);
		i++;
	}
	return (finder->valid_path->length ? TRUE : FALSE);
}

t_finder shorty_baby(t_cache cache, t_data data, t_map map)
{
	t_finder finder;
	t_dll_l path_l;

	char *tab = ft_0_new_memory(sizeof(char) * map->col);
	finder = new_finder(data, data->start_room, map, cache);
	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	split_path2(map, finder, path_l->content, tab);
	clean_woking(finder);

	split_all_path2(finder, map, tab);

	return (finder);
}