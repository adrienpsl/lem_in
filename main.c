#include <stdio.h>
#include "project/includes/function.h"

void print(t_cache cache)
{
	//	printf("new \n");
	//	dll_func(cache->new_path, print_cache_list);

	printf("work \n");
	dll_func(cache->working_path, print_cache_list);
	//	printf("**************************************************** \n");
}

int is_not_this_room(t_dll_l link, void *name_end_room)
{
	t_path path;

	path = link->content;
	path = path->prev;
	if (path->room == *(int *) name_end_room)
		return (FALSE);
	return (TRUE);
}

void keep_good_path(t_dll closed_path, t_dll good_path)
{
	t_path cur_room;
	t_dll_l current_path_link;
	t_dll_l tmp_link;
	char a;
	char b;

	// faire une new rev list pour chaque maillon
	current_path_link = dll_drop_link(closed_path, closed_path->top);
	cur_room = current_path_link->content;
	cur_room = cur_room->prev;
	a = cur_room->room + 'A';

	while (dll_find_and_drop(closed_path, is_not_this_room, &cur_room->room,
							 &tmp_link))
	{
		b = ((t_path)tmp_link->content)->prev->room + 'A';
		dll_add(tmp_link, good_path);
	}
}

void set_first_link(t_cache cache, t_map map)
{
	t_dll_l path_l;
	int res;

	path_l = new_path_link(cache->current_room, NULL, cache->all_path, 0);
	split_path(map, cache, path_l->content, &res);
	clean_woking(cache);
}


// une liste avec == mettre touts les path dans une liste chainer qui leurs
//  dans le bon ordre

t_dll_l     get_dll_by_path(t_path path)
{
    t_dll path_list;
    t_dll_l link;
    t_dll_l link_path_list;

    path_list = new_dll();
    while (path)
    {
        link = new_dll_l(path, sizeof(t_path_00));
        dll_push(link, path_list);
        path = path->prev;
    }
	link_path_list = new_dll_l_ptr(path_list);
    return (link_path_list);
}


t_dll     copy_all_path_order(t_dll_l close_path_link)
{
	t_dll dll_path;
	t_dll_l link_path_list;


	dll_path = new_dll();
	while (close_path_link)
	{
	    link_path_list = get_dll_by_path(close_path_link->content);
	    dll_push(link_path_list, dll_path);
	    close_path_link = close_path_link->next;
	}
	return (dll_path);
}

// pour chaque truc dans la liste check que j'ai bien le bon chemin

void     print_dll_path(t_dll_l dll_path_link)
{
    t_dll list;

    list = dll_path_link->content;
	dll_func(list, print_path_dll);
}

int main()
{
	setbuf(stdout, NULL);
	t_lem lem;
	t_algo algo;
	t_cache cache;
	t_map map;
	t_dll list;
	
	(void)list;
	lem = new_lem();
	algo = &lem->algo;
	map = &algo->map;
	cache = &algo->cache;

	set_first_link(cache, map);

	get_all_path(cache, map);
	dll_func(cache->close_path, print_path_dll);
	list = copy_all_path_order(cache->close_path->top);
	dll_func(list, print_dll_path);

	return EXIT_SUCCESS;
}