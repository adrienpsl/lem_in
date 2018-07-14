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

#include "../../all_includes.h"

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
int is_already_taken(t_path cur_path, int name_current_room)
{
	while (cur_path)
	{
		if (cur_path->room == name_current_room)
			return (TRUE);
		cur_path = cur_path->prev;
	}
	return (FALSE);
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
void split_one_path(t_map map, t_finder finder, t_path cur_path)
{
	char *map_line;
	t_dll_l path_link;
	size_t col;

	map_line = map->start + (cur_path->room * map->col);
	col = 0;
	while (col < map->col)
	{
		if (map_line[col] &&
			is_already_taken(cur_path, col) == FALSE)
		{
			path_link = new_path_link(col,
									  cur_path,
									  finder->all_path,
									  cur_path->size + 1);
			dll_add_at_index(path_link, finder->new_path,
							 finder->new_path->length);
		}
		++col;
	}
}

/*
**	**** VARIABLES
**	map					>	stock les connections entre toutes les rooms
**	finder				>	stock les data
**	cur_working_link	>	stock les data
**
**	**** RETURN
**	=> la taille de working_path
**
**	**** MAKING
**	parcourt les links de working_path
**	genere avec -- split_one_path --  les nouveaux path
**	nettoie et genere un nouveau cache avec --  clean_woking --
*/
size_t split_all_path_working(t_finder finder, t_map map)
{
	t_dll_l cur_working_link;

	cur_working_link = finder->working_path->top;
	while (cur_working_link)
	{
		split_one_path(map, finder, cur_working_link->content);
		cur_working_link = cur_working_link->next;
	}
	clean_woking(finder);
	return (finder->working_path->length);
}

/*
**	**** VARIABLES
**	data	>	data get par le parseur
**			>
**			>
**
**	**** RETURN
**	=>
**
**	**** MAKING
**
**
**
*/
void init_algo_little_map(t_cache cache, t_data data, t_map map)
{
	t_finder finder;

	finder = new_finder(data, data->start_room, map, cache);

	/*
	**    regarder si la start room n'a pas ete trouver directement
	 * 	  si elle n'est pas dans les 3 prochaine connection
	*/
	init_finder(finder, map);

	//	split_all_path_working(finder, map);
	//		 split_all_path_working(finder, map);
	while (split_all_path_working(finder, map))
	{
		//	{}
		dll_func(finder->working_path, print_path_dll);
	}

	// boucler tant que woking
	// get all path a chaque fois :)
}

void short_algo(t_cache cache, t_data data, t_map map)
{
	init_algo_little_map(cache, data, map);
}