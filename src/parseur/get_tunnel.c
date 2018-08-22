/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tunnel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:38:48 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:42:02 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int		find_room(t_dll_l link, void *ptr_str)
{
	char	*current_room;
	char	*room;

	current_room = ((t_room)link->content)->name;
	room = ptr_str;
	if (ft_strcmp(current_room, room) == 0)
		return (TRUE);
	return (FALSE);
}

int		check_same_tunnel_link(t_dll_l link, void *ptr_tunnel)
{
	t_tunnel	new_t;
	t_tunnel	list_t;

	list_t = link->content;
	new_t = ptr_tunnel;
	if ((list_t->room_1 == new_t->room_1 || list_t->room_1 == new_t->room_2)
			&& (list_t->room_2 == new_t->room_1
				|| list_t->room_2 == new_t->room_2))
		return (TRUE);
	else
		return (FALSE);
}

int		build_tunnel_link(t_data data, t_get_utils utils)
{
	t_dll_l		tunnel_link;
	t_dll_l		link;
	t_room		room_1;
	t_room		room_2;
	char		**split;

	split = ft_strsplit(utils->line, '-');
	tunnel_link = NULL;
	link = dll_find(data->room, find_room, *split);
	room_1 = link ? link->content : NULL;
	link = dll_find(data->room, find_room, *(split + 1));
	room_2 = link ? link->content : NULL;
	if (room_1 && room_2)
		tunnel_link = new_tunnel_link(room_1, room_2);
	if (tunnel_link && dll_find(data->tunnel,
				check_same_tunnel_link, tunnel_link->content) != NULL)
		destroy_dll_l(&tunnel_link);
	ft_free_split(&split);
	tunnel_link ? dll_add(tunnel_link, data->tunnel) : (void)1;
	return (tunnel_link ? TRUE : FALSE);
}

int		get_tunnel(t_data data, t_get_utils utils)
{
	int	last_line;

	last_line = 1;
	while (utils->line && (last_line || ask_gnl(utils->fd, &utils->line, NULL)))
	{
		if (utils->line[0] == '#')
			continue;
		else if (ft_strchr_how_many(utils->line, '-') == 1)
		{
			if (build_tunnel_link(data, utils) == FALSE)
				return (FALSE);
		}
		else
			break ;
		last_line = 0;
	}
	return (TRUE);
}
