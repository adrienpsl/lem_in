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
		(map->base + a)->link = 1;
		a = (x * data->room->length) + y;
		(map->base + a)->link = 1;
		tunnel_link = tunnel_link->next;
	}
}

void generate_map(t_map map)
{
	map->size = sizeof(t_tab_room_00) * map->y * map->y;
	map->base = ft_malloc_protect(map->size);
	map->work = ft_malloc_protect(map->size);
	map->line = ft_malloc_protect(sizeof(t_tab_room_00) * map->y);
	ft_bzero(map->base, map->size * 2 + sizeof(t_tab_room_00) * map->y);
}

void init_cache(t_cache cache, t_data data)
{
	cache->all_path = new_dll();
	cache->new_path = new_dll();
	cache->room = data->room;
	cache->working_path = new_dll();
}

/*
**    va set la peremiere salle comme path et initialisser les donnees
**    correctement pour lancer l'algo
*/
void set_up()
{
}

int main()
{
	t_lem lem;
	t_algo algo;
	t_data data;
	t_cache cache;
	t_map map;
	t_dll_l path_l;

	lem = new_lem();
	algo = &lem->algo;
	data = &lem->data;
	map = &algo->map;
	cache = &algo->cache;
	lem->data = lem_read_line();
	init_cache(cache, data);

	// A - B
	// une fois que la tab est generer j'ai plus rien a faire :).
	// mon objet map : je dois renomer les map, dans le meme ordre que la liste chainee, le x et le y sont donner par une fonction qui cherche chacune des
	// liaison : x et y.
	// c'est un carre donc dans un sens ou dans l'autre ca fait la meme chose.

	map->y = data->room->length;
	generate_map(map);
	set_tunnel(data, map);
	ft_memcpy(map->work, map->base, map->size);

	cache->current_room = data->start_nb;
	cache->current_room = 3;

	path_l = new_path_link(cache->current_room, NULL, cache->all_path, 0);
	binarie_line(map, cache, path_l->content);
	dll_func(cache->new_path, print_cache_list);


	//	cache->working_path =




		print_map(map->work, map->y);
	//	printf("%lu \n", sizeof(t_tab_room_00));
	return EXIT_SUCCESS;
}