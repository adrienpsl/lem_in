#include <stdio.h>
#include "project/includes/function.h"

void set_first_link(t_cache cache, t_map map)
{
	t_dll_l path_l;
	int res;

	path_l = new_path_link(cache->current_room, NULL, cache->all_path, 0);
	split_path(map, cache, path_l->content, &res);
	clean_woking(cache);
}

// une fonction pour les faires devenir plus beau !!!!!!!!! hahahaha :):):)
// je creer une list chaine avec un cpompteur sur chaque el,
// je les avance tous de 1;

//t_dll_l get_top_list_link(t_dll list)
//{
//
//}
// comme je connais la taille je peux demander un tab ?? youhou


void print_tab(t_dll_l tab)
{
	size_t i;

	i = 0;
	while (tab + i)
	{
		print_path_link(tab + i);
		++i;
	}
}

t_vt build_tab(t_dll list)
{
	t_vt tab;

	tab = new_void_tab(list->length);
	vt_get_dll(tab, list);

	return (tab);
}


int main()
{
	setbuf(stdout, NULL);
	t_lem lem;
	t_algo algo;
	t_cache cache;
	t_map map;
	t_dll free_list;
	t_vt tab;

	(void) free_list;
	lem = new_lem();
	algo = &lem->algo;
	map = &algo->map;
	cache = &algo->cache;

	cache->option = TRUE;
	set_first_link(cache, map);

	get_all_path(cache, map);
	free_list = copy_all_path_order(cache->close_path->top, NULL, NULL);

	printf("Inversion des path listes et transfere en liste chaine \n ---- \n");
	dll_func(free_list, print_list_dll_path);
	tab = build_tab(free_list);
//	print_tab(tab);

	destroy_dll_func(&free_list, free_list_list_path);
	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}