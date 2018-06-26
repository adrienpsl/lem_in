#include "../libft/include/dll_l_header.h"
#include "../includes/struct.h"

void     print_tunnel_room(t_dll_l room_link)
{
	t_room room;

	room = room_link->content;
	ft_printf("%s ", room->name);
//	ft_printf("%d ", room->x);
//	ft_printf("%d \n", room->y);
}


void     print_room(t_dll_l room_link)
{
		t_room room;

		room = room_link->content;
		ft_printf("*%s* \n", room->name);
//		ft_printf("%d ", room->x);
//		ft_printf("%d \n", room->y);
		ft_printf("---- \n");
		dll_func_lim(room->l_tube,room->l_tube->length, &print_tunnel_room);
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