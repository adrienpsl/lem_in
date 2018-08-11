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

int manage_end_start(int i, t_data data, t_get_utils utils)
{
	static int res;

	res = 0;
	if (utils->type_salle == L_START)
	{
		data->start_room = i;
		res = L_START;
	}
	if (utils->type_salle == L_END)
	{
		data->end_room = i;
		res = L_END;
	}
	utils->type_salle = 0;
	return (res);
}

t_dll_l add_room_link(t_data data, t_get_utils utils)
{
	static t_dll_l room_link;
	char **room_splited;
	static int i = 0;

	room_splited = ft_strsplit(utils->line, ' ');
	room_link = new_checked_room_link(*room_splited, *(room_splited + 1),
									  *(room_splited + 2), data);
	if (room_link)
		((t_room) room_link->content)->type = manage_end_start(i, data, utils);
	dll_add_at_index(room_link, data->room, data->room->length);
	ft_free_split(&room_splited);
	i++;
	return (room_link);
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



int check_err_room(t_data data)
{
	if (data->start_room < 0)
		ft_error("pas de start");
	if (data->end_room < 0)
		ft_error("pas de end");
	if (data->start_room == data->end_room)
		ft_error("start et end sont les memes");
	return (TRUE);
}

/*------------------------------------*\
    si count space == 2 --> je split et donne les 3 a create room_link
    si pas de space je stop
\*------------------------------------*/
int get_room(t_data data, t_get_utils utils)
{
	while (ask_gnl(utils->fd, &utils->line, NULL))
	{
		if (utils->line[0] == '#')
			utils->type_salle = manage_comment(utils->line);
		else if (ft_strchr_how_many(utils->line, ' ') == 2)
		{
			if (ft_strchr_how_many(utils->line, '-') > 0)
				return (print_err_retrun_int("- dans le nom de la room",
											 DEBUG->print_err));
			if (add_room_link(data, utils) == FALSE)
				break;
		}
		else
			break;
	}
	check_err_room(data);
	return (TRUE);
}
