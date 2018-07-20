#include <stdio.h>
#include "project/includes/function.h"

// liste chainer des chemins possibles que s'il y en a plus que le premiers
// je pars de la fin de la list, et des que il y a plus de chemin je remplace le
// tab definitif
/*------------------------------------*\
    parcours tout les chemins trouver dans la liste all_paths
    pour avoir une liste chainer des chemin independants les un des autres

    un tab pour mettre le nombre de chemin independants pour chaque chemin
\*------------------------------------*/

//void t_1(t_dll all_path_list, t_map map)
//{
//	t_dll list_out = new_dll();
//	char *tmp;
//	t_best_path path;
//	size_t i;
//
//	i = 0;
//	path = new_best_path(map->line);
//	(void) all_path_list;
//	(void) list_out;
//
//	path->cur_tab_good_path[i] = 1;
//
//	while (i < map->line)
//	{
//		find_best_path(i, map, path);
//		if (path->nb_independant_path > path->good_path_nb)
//		{
//			path->good_path_nb = path->nb_independant_path;
//			tmp = path->cur_tab_good_path;
//			path->cur_tab_good_path = path->tab_good_path;
//			path->tab_good_path = tmp;
//			//			printf("%d \n", path->good_path_nb);
//		}
//		//		printf("---------------------------------------------- \n");
//		ft_bzero(path->cur_tab_good_path, map->line);
//		++i;
//	}
//	print_line_path(path->tab_good_path, map->line);
//}






int main()
{
	setbuf(stdout, NULL);
	t_lem lem;
	t_algo algo;
	t_cache cache;
	t_map map;

	t_dll list;

	(void) list;
	(void) map;
	lem = new_lem();
	algo = &lem->algo;
	map = &algo->map;
	cache = &algo->cache;

	cache->option = TRUE;
	t_dll test_list = new_dll();
	(void) test_list;



	/*------------------------------------*\
	    algo petite map,
	    a definir ...
	\*------------------------------------*/

	short_algo(cache, lem->data, map);

	//	get_all_path(test_list, map, lem->data, cache);


	// find all path
	// list des path,

	/*------------------------------------*\
	    je print les paths et je relechis a comment leurs generer une start

	\*------------------------------------*/
	//	dll_func(cache->valid_path, print_path_dll);

	//	t_map_00 map_t1;
	//	generate_path_map(lem->data->room, cache->valid_path, &map_t1);
	//	t_1(cache->valid_path, &map_t1);
	// je copy chaque liste dans sont propre paht



	//	list = copy_all_path_order(cache->valid_path->top);

	// je fait le trie dans les chemin
	//	printf("Inversion des path listes et transfere en liste chaine \n ---- \n");
	//	dll_func(list, print_list_dll_path);

	//	test_1(list->top, list);
	//	test_1(list->top->next, list);
	//	dll_func(list, print_list_dll_path);

	//	printf("%d \n", lem->data->lim);
	//	destroy_dll_func(&list, free_list_list_path);
	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}