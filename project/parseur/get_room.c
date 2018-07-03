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

t_dll_l get_room(t_str_split split, t_data data, t_get_utils utils)
{
	t_dll_l room_link;
	t_room room;
	static int i = 0;

	room_link = new_room_link(*split->start, *(split->start + 1),
							  *(split->start + 2));
	if (utils->type_salle == L_START)
	{
		utils->start = room_link;
		data->start_room = i;
	}
	if (utils->type_salle == L_END)
	{
		utils->end = room_link;
		data->end_room = i;
	}
	utils->type_salle = 0;
	if (room_link && dll_find(data->room, is_right_room, room_link) != NULL)
		destroy_dll_l(&room_link);
	if (room_link)
	{
		room = room_link->content;
		get_size_map(data, room->x, room->y);
		room->nb = i++;
	}
	return (room_link);
}

void check_err_room(t_get_utils utils)
{
	if (utils->start == NULL)
		ft_error("pas de start");
	if (utils->end == NULL)
		ft_error("pas de end");
	if (utils->start == utils->end)
		ft_error("start et end sont les memes");
}

void  get_coord_room(t_data data, t_get_utils utils)
{
	static t_dll_l room_link;
	t_str_split split;

	split = NULL;
	while (ask_gnl(utils->fd, &utils->line))
	{
		split = new_str_split(utils->line, ' ');
		if (split->current && split->current[0] == '#')
			utils->type_salle = manage_comment(split);
		else if (split->all == 3)
		{
			room_link = get_room(split, data, utils);
			if (room_link == NULL)
				ft_error("err dans un link");
			else
				dll_add(room_link, data->room);
		}
		else
			break;
		destroy_str_split(&split);
	}
	destroy_str_split(&split);
}