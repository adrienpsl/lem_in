/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/08/17 15:31:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

int			manage_comment(char *comment_str)
{
	if (ft_strcmp(comment_str, "##start") == 0)
		return (L_START);
	else if (ft_strcmp(comment_str, "##end") == 0)
		return (L_END);
	return (FALSE);
}

int			lim_same_coord(t_room current_room, t_room new_room)
{
	if (current_room->x == new_room->x)
	{
		if (current_room->y == new_room->y)
		{
			print_err_retrun_null("same fucking coord", DEBUG->print_err);
			return (TRUE);
		}
	}
	return (FALSE);
}

int			lim_same_name(t_room current_room, t_room new_room)
{
	if (ft_strcmp(current_room->name, new_room->name) == 0)
	{
		print_err_retrun_null("same fucking name", DEBUG->print_err);
		return (TRUE);
	}
	return (FALSE);
}

int			is_right_room(t_dll_l link, void *ptr_new_room)
{
	t_room	new_room;
	t_room	current_room;

	new_room = ((t_dll_l)ptr_new_room)->content;
	current_room = link->content;
	if (lim_same_coord(current_room, new_room) == TRUE)
		return (TRUE);
	if (lim_same_name(current_room, new_room) == TRUE)
		return (TRUE);
	return (FALSE);
}
