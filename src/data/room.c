/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 15:09:12 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

/*
**check si x et y sont bien des int < 0
**verifie que
*/

t_dll_l		new_checked_room_link(char *name, char *x, char *y, t_data data)
{
	static	t_room_00	room;
	static	t_dll_l		room_link = NULL;

	if (str_is_int(x, &room.x) == FALSE || ft_atoi(x) < 0)
		return (print_err_retrun_null("x is fuck", DEBUG->print_err));
	if (str_is_int(y, &room.y) == FALSE || ft_atoi(x) < 0)
		return (print_err_retrun_null("y is fuck", DEBUG->print_err));
	room.name = ft_strdup(name);
	room_link = new_dll_l(&room, sizeof(t_room_00));
	if (dll_find(data->room, is_right_room, room_link) != NULL)
		destroy_dll_l(&room_link);
	return (room_link);
}

void		destroy_room(void *room_ptr)
{
	t_room room;

	room = room_ptr;
	free_str(&room->name);
	free(room);
}
