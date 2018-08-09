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

t_dll_l get_tunnel_link(char **split, t_data data, t_err1 err1)
{
	t_dll_l tunne_link;
	t_dll list_room;

	list_room = data->room;
	tunne_link = NULL;
	if (dll_find(list_room, find_room, *split) != NULL &&
		dll_find(list_room, find_room, *(split + 1)) != NULL)
	{
		tunne_link = new_tunnel_link(*split, *(split + 1));
		if (DEBUG->parseur == TRUE)
			printf("---> tunnel: %s -- %s \n", *split, *(split + 1));
	}
	else
		err1_add_err(err1, "la room n'existe pas", 0, NULL);
	return (tunne_link);
}

int build_tunnel_link(t_data data, t_get_utils utils)
{
	t_dll_l tunnel_link;
	char **split;

	split = ft_strsplit(utils->line, '-');
	tunnel_link = get_tunnel_link(split, data, utils->err);
	if (tunnel_link == NULL)
		err1_add_err(utils->err, "err dans un tunnel", 0, NULL);
	else
		dll_add(tunnel_link, data->tunnel);
	ft_free_split(&split);
	return (tunnel_link ? TRUE : FALSE);
}

int get_tunnel(t_data data, t_get_utils utils)
{
	int last_line = 1;

	while (last_line || ask_gnl(utils->fd, &utils->line, NULL))
	{
		if (utils->line[0] == '#')
			continue;
		else if (ft_strchr_how_many(utils->line, '-') == 1)
		{
			if (build_tunnel_link(data, utils) == FALSE)
				return (FALSE);
		}
		else if (ft_strchr_how_many(utils->line, '-') != 1)
			return (FALSE);
		else
			break;
		last_line = 0;
	}
	return (TRUE);
}
