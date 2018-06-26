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

int manage_comment(t_str_split split)
{
	if (ft_strcmp(split->current, "##start") == 0)
		return (L_START);
	else if (ft_strcmp(split->current, "##end") == 0)
		return (L_END);
	return (FALSE);
}

int lim_same_coord(t_room current_room, t_room new_room)
{
	if (current_room->x == new_room->x)
	{
		if (current_room->y == new_room->y)
			return (TRUE);
	}
	return (FALSE);
}

int lim_same_name(t_room current_room, t_room new_room)
{
	if (ft_strcmp(current_room->name, new_room->name) == 0)
		return (TRUE);
	return (FALSE);
}

int is_right_room(t_dll_l link, void *ptr_new_room)
{
	t_room new_room;
	t_room current_room;

	new_room = ((t_dll_l) ptr_new_room)->content;
	current_room = link->content;
	if (lim_same_coord(current_room, new_room) == TRUE)
		return (TRUE);
	if (lim_same_name(current_room, new_room) == TRUE)
		return (TRUE);
	return (FALSE);
}

void get_size_map(t_get_data data, int x, int y)
{
	if (x > data->x)
		data->x = x;
	if (y > data->y)
		data->y = y;
}