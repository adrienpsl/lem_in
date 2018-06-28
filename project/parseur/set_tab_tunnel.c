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

#include "../all_includes.h"

int same_name_room(t_dll_l link, void *ptr)
{
	t_room room;

	room = link->content;
	if (ft_strcmp(room->name, (char *) ptr) == 0)
		return (TRUE);
	return (FALSE);
}

t_dll_l get_room_link(t_dll room_list, char *room_str)
{
	t_dll_l room_link;

	room_link = dll_find(room_list, same_name_room, room_str);
	return (room_link);
}

void set_tab_tunnel(t_getter get)
{
	t_dll_l connection_link;
	t_tunnel tunnel;
	t_dll_l room_link_1;
	t_dll_l room_link_2;

	connection_link = get->data.tunnel->top;
	while (connection_link)
	{
	    tunnel = connection_link->content;
		room_link_1 = get_room_link(get->data.room, tunnel->room_1);
		room_link_2 = get_room_link(get->data.room, tunnel->room_2);
		connection_link = connection_link->next;
//		dll_func(get->data.room, &print_room_dll_l);
//		ft_printf("========================\n");
	}
}