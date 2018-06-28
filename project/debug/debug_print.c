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

void     print_tunnel(t_dll_l room_link)
{
	t_tunnel tunnel;

	tunnel = room_link->content;

	ft_printf("%s", tunnel->room_1);
	ft_printf("-");
	ft_printf("%s \n", tunnel->room_2);
}

// print les nouvelle salle au tour2



// print les chemin
// print les salles