/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:38:36 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 16:38:41 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/function.h"

void set_up()
{
	(void) "  ft_printf dans besoin du \n  ";
	setbuf(stdout, NULL);
}

void set_up_algo(t_lem lem, t_data data)
{
	t_map map;
	t_cache cache;
	t_algo algo;

	(void) "  set up cache  ";
	lem->algo = ft_0_new_memory(sizeof(t_algo_00));
	algo = lem->algo;

	cache = &algo->cache;
	cache->all_path = new_dll();
	cache->valid_path = new_dll();
	cache->end_room = data->end_room;
	(void) "  set up map  ";
	algo->map = ft_0_new_memory(sizeof(t_map_00));
	map = algo->map;
	map->col = data->room->length;
	map->line = data->room->length;
	map->size = data->room->length * data->room->length;
	map->map = ft_0_new_memory(map->size * sizeof(char));
	fill_map_with_tunnel(data, map);
}

void print_room_end(void *room_ptr)
{
	t_room room;

	room = room_ptr;
	if (room->type == L_START)
		ft_printf("##start\n");
	if (room->type == L_END)
		ft_printf("##end\n");;
	ft_printf("%s %d %d\n", room->name, room->x, room->y);
}

void print_tunnel_end(void *tunnel_ptr)
{
	t_tunnel tunnel;

	tunnel = tunnel_ptr;
	ft_printf("%s-%s\n", tunnel->room_1->name, tunnel->room_2->name);
}

void print_data(t_data data)
{
	ft_printf("%d \n", data->nb_fourmis);
	dll_func(data->room, &print_room_end);
	dll_func(data->tunnel, print_tunnel_end);
	ft_printf(" \n");
}

void kill_move(t_move move, size_t lim)
{
	t_real_path real;
	size_t i = 0;

	while (i < lim)
	{
		real = move->tab[i];
		destroy_dll(&real->list_path);
		free(real);
		++i;
	}
	free(move->tab);
	free(move);
}

int main()
{
	t_lem lem;
	t_move move = NULL;

	DEBUG = set_debug(FALSE);
	lem = ft_0_new_memory(sizeof(t_lem_00));
	if (read_and_parse_data(lem) == TRUE)
	{
		set_up_algo(lem, lem->data);
		move = algo(&lem->algo->cache, lem->data, lem->algo->map);
		if (move != NULL)
		{
			print_data(lem->data);
			manage_move(move);
			kill_move(move, move->size_tab);
		}
		else
			ft_printf("no solution\n");
	}
	else
		ft_printf("no solution\n");
	free_lem(lem);
	free(DEBUG);
	return (EXIT_SUCCESS);
}
