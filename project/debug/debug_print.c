#include "../all_includes.h"

void     print_tunnel_room(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("%s ", room->name);
//	ft_printf("%d ", room->x);
//	ft_printf("%d \n", room->y);
}


void     print_room(t_room room)
{
	ft_printf("*%s* \n", room->name);
	//		ft_printf("%d ", room->x);
	//		ft_printf("%d \n", room->y);
	ft_printf("---- \n");
	ft_printf(" \n");
}

void     print_room_dll_l(t_dll_l room_link)
{
		t_room room;

		room = room_link->content;
		ft_printf("*%s* \n", room->name);
		ft_printf("%d ", room->x);
		ft_printf("%d \n", room->y);
		ft_printf("---- \n");
		ft_printf(" \n");
}

void     print_tunnel_dll(t_dll_l room_link)
{
	t_tunnel tunnel;

	tunnel = room_link->content;

	ft_printf("%s", tunnel->c_room_1);
	ft_printf(" - ");
	ft_printf("%s \n", tunnel->c_room_2);
//	printf("%d - %d\n", tunnel->room_1, tunnel->room_2);

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


void     print_map(t_tab_room tab_room, size_t size_line)
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
		printf("%c ", (tab_room + i)->link ? 'X' : '.');
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