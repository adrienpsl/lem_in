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


void     free_lem(t_lem lem)
{
	destroy_map(&lem->algo.map);
	if (lem->data)
	{
		destroy_dll_func(&lem->data->room, &destroy_room);
		destroy_dll_func(&lem->data->tunnel, &destroy_tunnel);
	}
	free(lem);
}