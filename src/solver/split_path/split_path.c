/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 16:38:05 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/all_includes.h"

t_dll_l		new_path_link(int room, t_path prev, t_dll all_path, int size)
{
	t_path	path;

	path = ft_0_new_memory(sizeof(t_path_00));
	path->room = room;
	path->prev = prev;
	path->size = size;
	dll_ptr_add_create(path, all_path);
	return (new_dll_l_ptr(path));
}

/*
** VARIABLES
**	cur_path			>	list des room deja traverser par ce path
**	name_current_room	>	room linker avec la cur_room
**	**** RETURN
**	=> TRUE if the room if name_current_room is in cur_path
**	**** MAKING
**	Parcours tout les path precedent et compare a cur_room
*/

int			is_already_taken(t_path cur_path, int name_current_room)
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

void		split_path(t_map map, t_finder finder, t_path cur_path)
{
	char	*map_line;
	t_dll_l	path_link;
	size_t	col;

	map_line = map->map + (cur_path->room * map->col);
	col = 0;
	while (col < map->col)
	{
		if (map_line[col]
				&& is_already_taken(cur_path, col) == FALSE)
		{
			path_link = new_path_link(col, cur_path,
					finder->all_path, cur_path->size + 1);
			dll_add_at_index(path_link, finder->new_path,
					finder->new_path->length);
		}
		++col;
	}
}

void		deb_split(t_finder finder)
{
	if (DEBUG->print_split)
	{
		ft_printf("\n\n----> working path -- %lu\n", finder->working_path->length);
		dll_func(finder->working_path, print_path_dll);
		ft_printf("---- \n");
		ft_printf("----> valid path -- %lu \n", finder->valid_path->length);
		dll_func(finder->valid_path, print_path_dll);
		ft_printf("-------------------------------------------------------\n"
			"------------------------------------------------------------- \n");
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
**	genere avec -- split_path --  les nouveaux path
**	nettoie et genere un nouveau cache avec --  clean_woking --
*/

size_t		split_all_path(t_finder finder, t_map map)
{
	t_dll_l		cur_working_link;
	static int	i = 0;

	while (i < 9 && finder->working_path->length)
	{
		cur_working_link = finder->working_path->top;
		while (cur_working_link)
		{
			split_path(map, finder, cur_working_link->content);
			cur_working_link = cur_working_link->next;
		}
		deb_split(finder);
		clean_woking(finder);
		i++;
	}
	return (finder->valid_path->length ? TRUE : FALSE);
}
