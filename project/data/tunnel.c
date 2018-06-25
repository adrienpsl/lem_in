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

t_dll_l new_tunnel_link(char *room_1, char *room_2)
{
	t_tunnel_00 tunnel;
	t_dll_l tunnel_link = NULL;

	tunnel.room_1 = ft_strdup(room_1);
	tunnel.room_2 = ft_strdup(room_2);
	tunnel_link = new_dll_l(&tunnel, sizeof(t_tunnel_00));
	return (tunnel_link);
}

void destroy_tunnel(void *ptr_tunnel)
{
	static t_tunnel tunnel;

	tunnel = ptr_tunnel;
	free_str(&tunnel->room_1);
	free_str(&tunnel->room_2);
	free(tunnel);
}
