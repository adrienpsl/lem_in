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
	int count;

	cache_link = algo->working_path->top;
	count = algo->working_path->length;
	while (count)
	{

		get_new_path(cache_link->content, algo->all_path, algo->working_path);

		last_link = cache_link;
		cache_link = cache_link->next;
		dll_index_link(last_link, algo->working_path, &index);
		last_link = dll_drop_index(algo->working_path, index);
		destroy_dll_l_func(&last_link, dll_l_notfree_content);
		--count;
	}
}


void generate_first_path(t_algo algo, t_data data)
{
	t_dll_l last_link;
	size_t index;

	t_path start_room;
	t_dll_l tmp_start_room;


	start_room = new_path(0, NULL, data->start->content, algo->all_path);
	start_room->room->state = TAKEN;

	tmp_start_room = add_working_path(algo->working_path, start_room);
	get_new_path(start_room, algo->all_path, algo->working_path);

	// clean le old cache, je ne detruit pas room quand je fais ca
	dll_index_link(last_link, algo->working_path, &index);
	last_link = dll_drop_index(algo->working_path, index);
	destroy_dll_l_func(&last_link, dll_l_notfree_content);
	dll_func(algo->working_path, &print_path_dll);

}


void set_algo(t_algo algo, t_data data)
{

	algo->all_path = new_dll();
	algo->working_path = new_dll();
	algo->end = data->end->content;

	ft_printf("---------------------------------- \n");
	update_cache(algo);
	update_cache(algo);
	dll_func(algo->working_path, &print_path_dll);

	get_new_path(start_room, algo->all_path, algo->working_path);
	start_room->room->state = TAKEN;

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