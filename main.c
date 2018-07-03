#include <stdio.h>
#include "project/includes/function.h"

void set_first_link(t_cache cache, t_map map)
{
	t_dll_l path_l;
	int res;

	path_l = new_path_link(cache->start_room, NULL, cache->all_path, 0);
	split_path(map, cache, path_l->content, &res);
	clean_woking(cache);
}


// je prends le premier de ma liste et je le met dans une list chaine,
// je j'ai un tab cache qui fait la moitier de la liste chaine,


int same_where_path(t_dll_l list_1_link, void *list_2_ptr)
{
	t_path path_1;
	t_path path_2;
	t_dll list;

	list = list_1_link->content;
	path_1 = list->where->content;
	list = ((t_dll_l) list_2_ptr)->content;
	path_2 = list->where->content;

	//	printf("%c - ", path_1->room + 'A');
	//	printf("%c - ", path_2->room + 'A');


	return (path_1->room == path_2->room);
}

void test_1(t_dll_l first_link, t_dll list)
{
	t_dll_l cur_link;
	t_dll_l tmp_link;

	cur_link = first_link->next;

//	print_list_dll_path(first_link);
	printf("=======\n");
	while (cur_link)
	{
//		printf("%d \n", same_where_path(first_link, cur_link));
		if (same_where_path(first_link, cur_link))
		{
			tmp_link = cur_link;
//			print_list_dll_path(cur_link);
			printf("------ \n");
			cur_link = cur_link->next;
			dll_delete_link(list, tmp_link);
			continue;
		}
		cur_link = cur_link->next;
	}
}

int main()
{
	setbuf(stdout, NULL);
	t_lem lem;
	t_algo algo;
	t_cache cache;
	t_map map;

	t_dll list;

	(void) list;
	lem = new_lem();
	algo = &lem->algo;
	map = &algo->map;
	cache = &algo->cache;

	// je construit les data
	//	cache->option = TRUE;
	set_first_link(cache, map);

	// je range et garde les chemin qui matchs
	get_all_path(cache, map);
	list = copy_all_path_order(cache->close_path->top);

	// je fait le trie dans les chemin
	printf("Inversion des path listes et transfere en liste chaine \n ---- \n");
	dll_func(list, print_list_dll_path);

	test_1(list->top, list);
	test_1(list->top->next, list);
	dll_func(list, print_list_dll_path);

	printf("%d \n", lem->data->lim);
	destroy_dll_func(&list, free_list_list_path);
	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}