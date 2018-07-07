#include <stdio.h>
#include "project/includes/function.h"

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
	//	printf("=======\n");
	while (cur_link)
	{
		//		printf("%d \n", same_where_path(first_link, cur_link));
		if (same_where_path(first_link, cur_link))
		{
			tmp_link = cur_link;
			//			print_list_dll_path(cur_link);
			//			printf("------ \n");
			cur_link = cur_link->next;
			dll_delete_link(list, tmp_link);
			continue;
		}
		cur_link = cur_link->next;
	}
}

void add_all_path(char *map, t_dll_l path_link, size_t line)
{
	t_path path;

	path = path_link->content;
	path = path->prev;
	while (path->prev)
	{
		map[path->room + line] = 1;
		path = path->prev;
	}
}

void tests(t_dll room, t_dll path_lst, t_map map)
{

	t_dll_l link;
	size_t i;

	link = path_lst->top;
	map->line = room->length;
	map->col = path_lst->length;
	i = 0;
	map->map = ft_0_new_memory(sizeof(char) * map->line * map->col);
	while (link)
	{
		add_all_path(map->map, link, i * map->line);
		link = link->next;
		++i;
	}
	print_path_map(map->map, room->length, map->col);
}

/*------------------------------------*\
    une
\*------------------------------------*/
int cmp_line(char *cur_line, char *line, size_t lim)
{
	size_t i;

	i = 0;
	while (i < lim)
	{
		if (cur_line[i] && line[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

int check_all_case(char *tab_path_check, char *cur_line, t_map map)
{
	size_t i;

	i = 0;
	while (i < map->line)
	{
		if (tab_path_check[i] == 1)
		{
			if (cmp_line(map->map + (i * map->line), cur_line, map->line))
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

/*------------------------------------*\
    je compare avec dans le path
\*------------------------------------*/
void scan(size_t cur_line_nb, t_dll list_out, t_map map)
{
	size_t i;
	char *cur_lin_str;
	char *line_str;
	char *tab_taken_path;
	// un tab du nb de chemin

	tab_taken_path = ft_0_new_memory(map->line);
	(void) list_out;
	i = 0;
	cur_lin_str = map->map + (cur_line_nb * map->col);
	line_str = map->map;
	tab_taken_path[cur_line_nb] = 1;
	printf(" \n");
	print_line(cur_lin_str, map->line, 1);
	while (i < map->col)
	{
		// je compare la ligne du tab avec toute les autres ligne valide
		// if check autre ligne == ok // set dans le tab la bonne case.
		if (cmp_line(line_str + (i * map->line), cur_lin_str, map->line) ==
			FALSE)
		{
			print_line(line_str + (i * map->line), map->line, 1);
			// je le compare avec tout les tab deja generer,
		}
		++i;
	}
}

void t_1(t_dll path, t_map map)
{
	t_dll list_out = new_dll();
	//	size_t i;
	//
	//	i = 0;
	(void) path;
	scan(0, list_out, map);
	//	while (i < map->line)
	//	{
	//	}
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

	//	cache->option = TRUE;
	get_all_path(cache, map);

	/*------------------------------------*\
	    je print les paths et je relechis a comment leurs generer une map

	\*------------------------------------*/
	dll_func(cache->close_path, print_path_dll);

	t_map_00 map_t1;
	tests(lem->data->room, cache->close_path, &map_t1);
	t_1(cache->close_path, &map_t1);
	// je copy chaque liste dans sont propre paht



	//	list = copy_all_path_order(cache->close_path->top);

	// je fait le trie dans les chemin
	//	printf("Inversion des path listes et transfere en liste chaine \n ---- \n");
	//	dll_func(list, print_list_dll_path);

	//	test_1(list->top, list);
	//	test_1(list->top->next, list);
	//	dll_func(list, print_list_dll_path);

	printf("%d \n", lem->data->lim);
	//	destroy_dll_func(&list, free_list_list_path);
	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}