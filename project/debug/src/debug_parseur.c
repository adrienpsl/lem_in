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

#include "../../all_includes.h"

void print_tunnel_room(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("%s ", room->name);
	//	ft_printf("%d ", room->line);
	//	ft_printf("%d \n", room->col);
}

void print_room(t_room room)
{
	ft_printf("*%s* \n", room->name);
	//		ft_printf("%d ", room->line);
	//		ft_printf("%d \n", room->col);
	ft_printf("---- \n");
	ft_printf(" \n");
}

void     print_all_tunnel(t_dll tunnel_list)
{
	t_dll_l link;

	link = tunnel_list->top;
}

void print_room_dll_l(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("%5s || ", room->name);
	ft_printf("%5d ||", room->x);
	ft_printf("%5d || ", room->y);
	if (room->type == L_START)
	    printf("start");
	if (room->type == L_END)
		printf("end");
	printf(" \n");
}

void print_tunnel_dll(t_dll_l room_link)
{
	t_tunnel tunnel;

	tunnel = room_link->content;

	ft_printf("%s", tunnel->c_room_1);
	ft_printf(" - ");
	ft_printf("%s \n", tunnel->c_room_2);
	//	printf("%d - %d\n", tunnel->room_1, tunnel->room_2);

}