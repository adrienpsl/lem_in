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

t_best_path new_best_path(size_t nb_path)
{
	t_best_path best;
	t_b_path cache;

	best = ft_0_new_memory(sizeof(t_best_path_00));
	cache = &best->cache;
	cache->tab = ft_0_new_memory(sizeof(char) * nb_path);
//	cache->nb = 1;
	//	print_line_first_int(best->tab_good_path, nb_path, 0);
	//	print_line_first_int(best->cur_tab_good_path, nb_path, 0);
	return (best);
}

// set up les path possible en fonction des connection
t_real_path new_real_path()
{
	t_real_path real_path;

	real_path = ft_0_new_memory(sizeof(t_real_path_00));
	return (real_path);
}

/*------------------------------------*\
 pour chaque cel du tab, je creer ma liste chainer,
 mettre dans liste chainer tout les trucs

\*------------------------------------*/
t_real_path generate_all_move(t_best_path best_path)
{
	t_real_path real;

	real = ft_0_new_memory(
	 sizeof(t_real_path_00) * best_path->data.nb);
	// set la premier cel du tab et free les path ? yep !

	return (real);
}

void short_algo(t_cache cache, t_data data, t_map map)
{
	t_finder finder;

	finder = new_finder(data, data->start_room, map, cache);
	/*
	**    regarder si la start room n'a pas ete trouver directement
	 * 	  si elle n'est pas dans les 3 prochaine connection
	*/
	init_finder(finder, map);

	while (split_all_path_working(finder, map))
	{
		//		dll_func(finder->working_path, print_path_dll);
	}
	generate_path_map(data->room,
					  finder->valid_path,
					  map);
//	print_path_map_2(map);

	t_best_path best;
	best = new_best_path(map->line);
	find_best_path(map, best);

	t_real_path move = new_real_path();
	move->tab_best_path = best->data.tab;

	//	manage_max_path(data, map->col, move->tab_best_path);
//	print_line_first_int(move->tab_best_path, map->line, 0);
}

// je compte par chemin le temps que ca me prends d'etre full,
// un tab avec les chemin et le temps pour qu'il soit full ?