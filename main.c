#include <stdio.h>
#include "project/includes/function.h"

void set_up()
{
	(void) "  printf dans besoin du \n  ";
	setbuf(stdout, NULL);
}

void set_up_algo(t_algo algo, t_data data)
{
	t_map map;
	t_cache cache;

	(void)"  set up cache  ";
	cache = &algo->cache;
	cache->all_path = new_dll();
	cache->valid_path = new_dll();
	cache->end_room = data->end_room;
	(void)"  set up map  ";
	map = &algo->map;
	map->col = data->room->length;
	map->line = data->room->length;
	map->size = data->room->length * data->room->length;
	map->map = ft_0_new_memory(map->size * sizeof(char));
	fill_map_with_tunnel(data, map);
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
	move = short_algo(&lem->algo.cache, lem->data, &lem->algo.map);

	// manage lem
	//	algo = &lem->algo;
	//	map = &algo->map;
	//	cache = &algo->cache;
	//
	//	cache->option = TRUE;
//	t_dll test_list = new_dll();
//	(void) test_list;
//
//	/*------------------------------------*\
//	    algo petite map,
//	    a definir ...
//	\*------------------------------------*/
//	t_move move;
//	move = short_algo(cache, lem->data, map);
//
	manage_move(move);
//
//	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}


/*
 * plan :
 * 	new_lem
 * 	set lem ==>
 *
 *
 * */