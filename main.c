#include <stdio.h>
#include "project/includes/function.h"

void set_up()
{
	(void) "  printf dans besoin du \n  ";
	setbuf(stdout, NULL);
}

int main()
{
	set_up();
	DEBUG = set_debug();


	t_lem lem;
	lem = new_lem();
	read_and_parse_data(lem);
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
//	manage_move(move);
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