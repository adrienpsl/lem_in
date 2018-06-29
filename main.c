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

void print_name(int a)
{
	int i;

	i = 'A';
	printf("[[ ");
	while (i < a+ 'A')
	{
	    printf("%c ", i);
		++i;
	}
	printf("]]\n");
}


void     print_map(t_algo algo)
{
	size_t i;
	t_tab_room current_tab;
	size_t line;
	int letter;

	i = 0;
	line = 0;
	letter = 'B';

	current_tab = algo->map;

	print_name(algo->y_map);
	printf("\nA  ");
	while (i < algo->y_map * algo->y_map)
	{
		printf("%c ", (current_tab + i)->link ? 'X' : '.');
		++i;
		++line;
		if (line == algo->y_map)
		{
			printf(" \n%c  ", letter);
			letter++;
			line = 0;
		}
	}
	printf("\n");
}

void set_tunnel(t_data data, t_algo algo)
{
	t_dll_l tunnel_link;
	t_tunnel tunnel;
	size_t x;
	size_t y;
	int a;
	(void) algo;

	tunnel_link = data->tunnel->top;
	//
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;
		dll_index_link_func(data->room, same_name, tunnel->c_room_2, &x);
		dll_index_link_func(data->room, same_name, tunnel->c_room_1, &y);
		// si x est plus grand, je prend y
		a = (y * data->room->length) + x;
		(algo->map + a)->link = 1;
		a = (x * data->room->length) + y;
		(algo->map + a)->link = 1;
		print_map(algo);
		tunnel_link = tunnel_link->next;
	}
}

int main()
{
	t_lem lem;
	t_algo algo;
	t_data data;
	size_t all_map;

	lem = new_lem();
	lem->data = lem_read_line(NULL);
	algo = &lem->algo;
	data = &lem->data;

	// A - B
	// une fois que la tab est generer j'ai plus rien a faire :).
	// mon objet map : je dois renomer les map, dans le meme ordre que la liste chainee, le x et le y sont donner par une fonction qui cherche chacune des
	// liaison : x et y.
	// c'est un carre donc dans un sens ou dans l'autre ca fait la meme chose.

	algo->y_map = data->room->length;
	all_map =  sizeof(t_tab_room_00) * algo->y_map * algo->y_map;
	algo->map = ft_malloc_protect(all_map);
	ft_memset(algo->map, 0, all_map);
	set_tunnel(data, algo);
	print_map(algo);

	return 0;
}