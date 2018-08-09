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

#include "../all_includes.h"

void manage_end_start(int i, t_data data, t_get_utils utils)
{
	if (utils->type_salle == L_START)
		data->start_room = i;
	if (utils->type_salle == L_END)
		data->end_room = i;
	utils->type_salle = 0;
}

t_dll_l create_room_link(char **room_splited, t_data data, t_get_utils utils)
{
	t_dll_l room_link;
	t_room room;
	static int i = 0;

	room_link = new_room_link(*room_splited, *(room_splited + 1),
							  *(room_splited + 2));
	// check room link
	manage_end_start(i, data, utils);

	if (dll_find(data->room, is_right_room, room_link) != NULL)
		destroy_dll_l(&room_link);
	if (room_link)
	{
		room = room_link->content;
		get_size_map(data, room->x, room->y);
		room->nb = i++;
	}
	// check les err de rooms
	return (room_link);
}

t_dll_l room_add_link(t_data data, t_get_utils utils)
{
	static t_dll_l room_link;
	char **room_splited;

	room_splited = ft_strsplit(utils->line, ' ');
	room_link = create_room_link(room_splited, data, utils);

	dll_add(room_link, data->room);
	ft_free_split(&room_splited);
	return (room_link);
}

/*------------------------------------*\
    si count space == 2 --> je split et donne les 3 a create room_link
    si pas de space je stop
\*------------------------------------*/
void get_coord_room(t_data data, t_get_utils utils)
{
	size_t nb_line;
	while (ask_gnl(utils->fd, &utils->line, &nb_line))
	{
		if (utils->line[0] == '#')
			utils->type_salle = manage_comment(utils->line);
		else if (ft_strchr_how_many(utils->line, ' ') == 2)
		{
			if (room_add_link(data, utils) == FALSE)
				break;
		}
		else if (ft_strchr_how_many(utils->line, ' ') != 2)
			err1_add_err(utils->err,
						 "une room est imcomplete", 0, utils->line);
		else
			break;
	}
}

/*
**	**** VARIABLES
**
**	**** RETURN
**
**	**** MAKING
**	verifie une fois toutes les rooms lue,
**	et affiche un message d'erreur en  consequence
*/

void check_err_room(t_get_utils utils)
{
	if (utils->start == NULL)
		ft_error("pas de start");
	if (utils->end == NULL)
		ft_error("pas de end");
	if (utils->start == utils->end)
		ft_error("start et end sont les memes");
}

void get_room(t_data data, t_get_utils utils)
{
	get_coord_room(data, utils);
//	check_err_room(utils);
}