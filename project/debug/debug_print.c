#include "../all_includes.h"

void print_tunnel_room(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("%s ", room->name);
	//	ft_printf("%d ", room->x);
	//	ft_printf("%d \n", room->y);
}

void print_room(t_room room)
{
	ft_printf("*%s* \n", room->name);
	//		ft_printf("%d ", room->x);
	//		ft_printf("%d \n", room->y);
	ft_printf("---- \n");
	ft_printf(" \n");
}

void print_room_dll_l(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("*%s* \n", room->name);
	ft_printf("%d ", room->x);
	ft_printf("%d \n", room->y);
	ft_printf("---- \n");
	ft_printf(" \n");
}

void print_tunnel_dll(t_dll_l room_link)
{
	t_tunnel tunnel;

	tunnel = room_link->content;

	ft_printf("%s", tunnel->c_room_1);
	ft_printf(" - ");
	ft_printf("%s \n", tunnel->c_room_2);
	//	printf("%d - %d\n", tunnel->room_1, tunnel->room_2);

}

void print_cache_list(t_dll_l path_link)
{
	t_path path;

	path = path_link->content;

	printf("%c <-- ", path->prev->room + 'A');
	printf("%d - ", path->size);
	printf("%c\n", path->room + 'A');
}

/*
**    print map
*/

void print_name(int a)
{
	int i;

	i = 'A';
	printf("[[ ");
	while (i < a + 'A')
	{
		printf("%c ", i);
		++i;
	}
	printf("]]\n");
}

void print_map(char *tab_room, size_t size_line)
{
	size_t i;
	size_t line;
	int letter;
	size_t lim;

	i = 0;
	line = 0;
	letter = 'B';
	lim = size_line * size_line;

	print_name(size_line);
	printf("\nA  ");
	while (i < lim)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
		++line;
		if (line == size_line)
		{
			printf(" \n%c  ", letter);
			letter++;
			line = 0;
		}
	}
	printf("\n");
}

void print_path(t_path path)
{
	while (path)
	{
		printf("%c - ", path->room + 'A');
		path = path->prev;
	}
	printf(" \n");
}

void     print_path_dll(t_dll_l link)
{
	print_path(link->content);
}

void print_line(char *tab_room, size_t size_line, int cur_line)
{
	size_t i;

	i = 0;

	print_name(size_line);
	printf("\n%c  ", 'A' + cur_line);
	while (i < size_line)
	{
		printf("%c ", tab_room[i] ? 'X' : '.');
		++i;
	}
	printf("\n");
}