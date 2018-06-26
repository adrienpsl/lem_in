#include <stdio.h>
#include "project/includes/function.h"

t_lem new_lem()
{
	t_lem lem;

	lem = ft_malloc_protect(sizeof(t_lem_00));
	ft_bzero(lem, sizeof(t_lem_00));
	lem->algo.all_path = new_dll();
	return (lem);
}

// je creer la premiere liste chainee, celle du depart
// je parcours les connection de

//t_dll_l last_room(t_path path)
//{
//	return (path->top);
//}
//
/*
**    genere un nouveau path et le set avec les ancienne val du old path,
*/
//
//t_path get_path(t_path currrent_path, t_dll all_path)
//{
//	t_path new_path;
//	t_dll_l path_link;
//
//	new_path = new_dll();
//	new_path->length = currrent_path->length;
//	new_path->top = currrent_path->top;
//	new_path->end = currrent_path->end;
//	path_link = new_dll_l_ptr(new_path);
//	dll_add(path_link, all_path);
//	return (new_path);
//}

// pour toute la liste de la room actuelle je fais un nouvaux chemin - 1
// le link a changer, le truc a
// j'ajoute a la liste les nouveau chemin
//void split_path(t_path current_p, t_dll all_path)
//{
//	dll_func(current_p, &print_room_dll_l);
//	//
////	if ()
////	    ;
//}

t_path new_path(int size, t_path prev_path, t_room room, t_dll all_path)
{
	t_path path;
	t_dll_l path_link;

	path = ft_malloc_protect(sizeof(t_path_00));
	path->size = size;
	path->prev = prev_path;
	path->room = room;
	path_link = new_dll_l_ptr(path);
	dll_add(path_link, all_path);
	return (path);
}

void     print_path(t_path path)
{
    print_room(path->room);
}

void     print_path_list(t_path path)
{
	while (path)
	{
	    print_path(path);
		path = path->prev;
	}
}



void get_new_path(t_path curent_path, t_dll all_path)
{
	t_path N_path;
	t_dll l_tunnel;
	t_room room;
	int size;

	l_tunnel = curent_path->room->l_tube;
	room = ((t_room)l_tunnel->top->content);
	size = curent_path->size + 1;

	N_path = new_path(size, curent_path, room, all_path);
	print_path_list(N_path);
	//	print_room(N_path->room);
}

// je dois parcourir la dll
//void tt()
//{
//	while (tube)
//	{
//
//	}
//}

void set_algo(t_lem lem)
{
	lem->algo.all_path = new_dll();
	lem->algo.end = lem->data.end;
}

void set_first_room(t_lem lem)
{
	t_path start;

	start = new_path(0, NULL, lem->data.start->content, lem->algo.all_path);

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



//	all_path = new_dll();
//	start = new_path(0, NULL, data->start->content, all_path);
//	get_new_path(start, all_path);
//
	// pour chaque - 1 new room j'ajoute un chemin

	//	split_path(start, all_path);

	return 0;
}