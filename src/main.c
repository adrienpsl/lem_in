#include <stdio.h>
#include "includes/function.h"

void set_up()
{
	(void) "  printf dans besoin du \n  ";
	setbuf(stdout, NULL);
}

void set_up_algo(t_algo algo, t_data data)
{
	t_map map;
	t_cache cache;

	(void) "  set up cache  ";
	cache = &algo->cache;
	cache->all_path = new_dll();
	cache->valid_path = new_dll();
	cache->end_room = data->end_room;
	(void) "  set up map  ";
	map = &algo->map;
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
	    printf("##start\n");
	if (room->type ==L_END)
	    printf("##end\n");;
	printf("%s %d %d\n", room->name, room->x, room->y);
}

void print_tunnel_end(void *tunnel_ptr)
{
	t_tunnel tunnel;

	tunnel = tunnel_ptr;
	printf("%s-%s\n", tunnel->room_1->name, tunnel->room_2->name);
}

void print_data(t_data data)
{
	printf("%d \n", data->nb_fourmis);
	dll_func(data->room, &print_room_end);
	dll_func(data->tunnel, print_tunnel_end);
	printf(" \n");
}

int main()
{
	set_up();
	DEBUG = set_debug();

	t_lem lem;
	t_move move;
	lem = ft_0_new_memory(sizeof(t_lem_00));
	read_and_parse_data(lem);
	set_up_algo(&lem->algo, lem->data);
	move = algo(&lem->algo.cache, lem->data, &lem->algo.map);
	if (move != NULL)
	{
		print_data(lem->data);
		manage_move(move);
	}

	free_lem(lem);
	return EXIT_SUCCESS;
}
