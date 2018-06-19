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

#include "../includes/all_includes.h"

t_dll_l new_room_link(char *x, char *y, char *name)
{
	static t_room_00 room;
	static t_dll_l room_link = NULL;

	room.x = atoi(x);
	room.y = atoi(y);
	room.name = ft_strdup(name);
	room.l_tube = new_dll();
	room_link = new_dll_l(&room, sizeof(t_room_00));
	return (room_link);
}

void     destroy_room(t_room room)
{
    	free_str(&room->name);
		destroy_dll(&room->l_tube);
		free(room);
}
