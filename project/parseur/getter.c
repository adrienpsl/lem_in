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

/*------------------------------------*\
    changer le fd dans les functions
\*------------------------------------*/

#include "../includes/all_includes.h"

/*
**    get le bon nb de fourmis
*/
void get_nb_foumis(t_getter get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line);
	if (is_int(get->utils.line, &result) == FAIL || result <= 0)
		ft_error("Il n'y a pas de fourmis OU le nb n'est pas Valable");
	get->data.nb_fourmis = result;
}

int manage_comment(t_str_split split)
{
	if (ft_strcmp(split->current, "##start") == 0)
		return (L_START);
	else if (ft_strcmp(split->current, "##end") == 0)
		return (L_END);
	return (FALSE);
}

// check que toutes les entree soit des nombres
// rien faire pour le L:
t_dll_l get_room(t_str_split split, t_get_data data, t_get_utils utils)
{
	t_dll_l room_link;

	room_link = new_room_link(split->current,
							  split->current + 1,
							  split->current + 2);
	if (utils->type_salle == L_START)
	    data->start = room_link;
	if (utils->type_salle == L_END)
		data->end = room_link;
	return (room_link);
}

void get_coord_room(t_getter get)
{
	static t_get_utils utils;
	static t_dll_l room_link;
	t_str_split split;

	utils = &get->utils;
	while (ask_gnl(utils->fd, &utils->line))
	{
		split = new_str_split(utils->line, ' ');
		if (split->all == 3)
		{
			room_link = get_room(split, &get->data, &get->utils);
			if (room_link == NULL)
				break;
			else
				dll_add(room_link, get->data.room);
		}
		if (split->all == 1 &&
			split->current[0] == '#')
			utils->type_salle = manage_comment(split);
		else
			break;
		destroy_str_split(&split);
	}
	destroy_str_split(&split);
}
// fonction qui gere deuxieme vague


// premiere fonction get sur gnl les data
void lem_read_line()
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data.room = new_dll();
	get.data.connextion = new_dll();


	get.utils.fd = open_file(
	 "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2");
	get_nb_foumis(&get);

	get_coord_room(&get);
	free_str(&get.utils.line);
}
