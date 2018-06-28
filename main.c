#include <stdio.h>
#include "project/includes/function.h"

t_dll_l add_working_path(t_dll working_path, t_path room);

/*
**    ajoute au cache tout les nouveaux embranchement
*/
void get_new_path(t_path curent_path, t_dll all_path, t_dll working_path)
{
	t_dll_l tunnel_link;
	t_path path;
	t_room room;
	int size;

	tunnel_link = curent_path->room->l_tube->top;
	size = curent_path->size + 1;

	while (tunnel_link)
	{
		room = tunnel_link->content;
		if (room->state == 0)
		{
			path = new_path(size, curent_path, room, all_path);
			room->state = TAKEN;
			path->prev = curent_path;
			add_working_path(working_path, path);
		}
		tunnel_link = tunnel_link->next;
	}
	//	print_room(N_path->room);
}

/*	je parcourds le cache
 * 	a chaque pachemin,
 * 			si embranchement -> je lance get_path
 * 			si rien, je delete le cache
 * */
void update_cache(t_algo algo)
{
	t_dll_l cache_link;
	t_dll_l last_link;
	size_t index;

	cache_link = algo->working_path->top;
	//	while (cache_link)
	//	{

	get_new_path(cache_link->content, algo->all_path, algo->working_path);

	last_link = cache_link;
	dll_index_link(last_link, algo->working_path, &index);
	last_link = dll_drop_index(algo->working_path, index);
	destroy_dll_l_func(&last_link, dll_l_notfree_content);
	cache_link = cache_link->next;

	//	}
}

void set_algo(t_lem lem)
{
	lem->algo.all_path = new_dll();
	lem->algo.end = lem->data.end->content;
	lem->algo.working_path = new_dll();
}

void set_first_room(t_lem lem)
{
	t_path start;
	t_algo algo;
	t_dll_l last_link;
	size_t index;

	start = new_path(0, NULL, lem->data.start->content, lem->algo.all_path);
	algo = &lem->algo;
	last_link = add_working_path(lem->algo.working_path, start);

	// mise a jour du cash
	get_new_path(start, algo->all_path, algo->working_path);
	start->room->state = TAKEN;

	// clean le old cache, je ne detruit pas room quand je fais ca
	dll_index_link(last_link, algo->working_path, &index);
	last_link = dll_drop_index(algo->working_path, index);
	destroy_dll_l_func(&last_link, dll_l_notfree_content);
	dll_func(algo->working_path, &print_path_dll);
	ft_printf("---------------------------------- \n");
	update_cache(algo);
	dll_func(algo->working_path, &print_path_dll);
}

int main()
{
	//	t_dll_l link;

	t_lem lem;
	//	t_data_00 *data;

	lem = new_lem();
	lem->data = lem_read_line(NULL);

	set_algo(lem);
	set_first_room(lem);
	free_lem(lem);

	//	all_path = new_dll();
	//	start = new_path(0, NULL, data->start->content, all_path);
	//	get_new_path(start, all_path);
	//
	// pour chaque - 1 new room j'ajoute un chemin

	//	split_path(start, all_path);

	return 0;
}