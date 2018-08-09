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

// la fonction prends la premiere room et la recherche

int find_room(t_dll_l link, void *ptr_str)
{
	char *current_room;
	char *room;

	current_room = ((t_room) link->content)->name;
	room = ptr_str;
	if (ft_strcmp(current_room, room) == 0)
		return (TRUE);
	return (FALSE);
}

t_dll_l get_tunnel_link(t_str_split split, t_data data)
{
	t_dll_l tunne_link;
	t_dll list_room;

	list_room = data->room;

	if (dll_find(list_room, find_room, *split->start) != NULL &&
		dll_find(list_room, find_room, *(split->start + 1)) != NULL)
	{
		tunne_link = new_tunnel_link(*split->start, *(split->start + 1));
	}
	else
		tunne_link = NULL;
	return (tunne_link);
}

void get_tunnel(t_data data, t_get_utils utils)
{
//	t_dll_l tunnel_link;
	(void)data;
	char **split;
	int signal = 1;

	while (signal || ask_gnl(utils->fd, &utils->line, NULL))
	{
		if (utils->line[0] == '#')
			continue ;
		else if (ft_strchr_how_many(utils->line, '-') == 1)
		split = ft_strsplit(utils->line, '-');
		else if (2 == 2)
		{
//			tunnel_link = get_tunnel_link(split, data);
//			if (tunnel_link == NULL)
//				ft_error("err dans un tunnel");
//			else
//				dll_add(tunnel_link, data->tunnel);
		}
		else
			break;
		signal = 0;
	}
}
