#include <stdio.h>
#include "project/includes/function.h"

/* je get l'index de la connetion*/

int same_name(t_dll_l current_link, void *ptr)
{
	t_room room;

	room = current_link->content;
	if (ft_strcmp(room->name, ptr) == 0)
		return (TRUE);
	return (FALSE);
}

void set_tunnel(t_data data, t_map map)
{
	t_dll_l tunnel_link;
	t_tunnel tunnel;
	size_t x;
	size_t y;
	size_t a;

	tunnel_link = data->tunnel->top;
	//
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;
		dll_index_link_func(data->room, same_name, tunnel->c_room_2, &x);
		dll_index_link_func(data->room, same_name, tunnel->c_room_1, &y);
		// si x est plus grand, je prend y
		a = (y * data->room->length) + x;
		map->base[a] = 1;
		a = (x * data->room->length) + y;
		map->base[a] = 1;
		tunnel_link = tunnel_link->next;
	}
}

void generate_map(t_map map)
{
	map->size = sizeof(char) * map->y * map->y;
	map->base = ft_malloc_protect(map->size);
	map->work = ft_malloc_protect(map->size);
	ft_bzero(map->base, map->size * 2 + sizeof(char) * map->y);
}

void print(t_cache cache)
{
	//	printf("new \n");
	//	dll_func(cache->new_path, print_cache_list);

	printf("work \n");
	dll_func(cache->working_path, print_cache_list);
	//	printf("**************************************************** \n");
}

// si res est fuck

size_t tes(t_cache cache, t_map map)
{
	t_dll_l current_work;
	int res;

	current_work = cache->working_path->top;
	while (current_work)
	{
		binarie_line(map, cache, current_work->content, &res);
		current_work = current_work->next;
		if (res == 0)
			dll_drop_link(cache->working_path, current_work->prev);
	}
	clean_woking(cache);
	return (cache->working_path->length);
}

// stoker tout les chemins qui passent par i et les ranger
// pour les comparer ensuite et voir les plus rapides :)

int main()
{
	t_lem lem;
	t_algo algo;
	t_data data;
	t_cache cache;
	t_map map;
	t_dll_l path_l;
	int res;

	lem = new_lem();
	algo = &lem->algo;
	data = &lem->data;
	map = &algo->map;
	cache = &algo->cache;
	lem->data = lem_read_line();
	init_cache(cache, data);
	//
	//	// A - B
	//	// une fois que la tab est generer j'ai plus rien a faire :).
	//	// mon objet map : je dois renomer les map, dans le meme ordre que la liste chainee, le x et le y sont donner par une fonction qui cherche chacune des
	//	// liaison : x et y.
	//	// c'est un carre donc dans un sens ou dans l'autre ca fait la meme chose.
	//
	map->y = data->room->length;
	generate_map(map);
	set_tunnel(data, map);
	ft_memcpy(map->work, map->base, map->size);

	cache->current_room = data->start_nb;
	//
	path_l = new_path_link(cache->current_room, NULL, cache->all_path, 0);
	binarie_line(map, cache, path_l->content, &res);
	clean_woking(cache);
	print(cache);

	//	tes(cache, map);
	//	print(cache);
	//
	//	tes(cache, map);
	//	print(cache);
	//
	//	tes(cache, map);
	//	print(cache);
	//
	//	dll_func(cache->working_path, print_path_dll);
	//
	//	tes(cache, map);
	//
	//	dll_func(cache->working_path, print_path_dll);

	//	print_path(cache->working_path->top->content);
	while (tes(cache, map))
	{}
	print(cache);

	// print path



	//	cache->working_path =




	//		print_map(map->work, map->y);
	//	printf("%lu \n", sizeof(t_tab_room_00));
	return EXIT_SUCCESS;
}