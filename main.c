#include <stdio.h>
#include "project/includes/function.h"

void set_up()
{
	(void) "  printf dans besoin du \n  ";
	setbuf(stdout, NULL);
}

t_debug_struct set_debug()
{
	t_debug_struct db;
	
	db = ft_0_new_memory(sizeof(t_debug_struct_00));
	(void)"  set les demandes de debug  ";
	db->parseur = TRUE;
	
	(void)"  set le fichier a check  ";
	db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2";
	return (db);
}

t_debug_struct DEBUG;

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