#include "../libft/include/dll_l_header.h"
#include "../includes/struct.h"

void     print_room(t_dll_l room_link)
{
		t_room room;

		room = room_link->content;

		ft_printf("%s ", room->name);
		ft_printf("%d ", room->x);
		ft_printf("%d \n", room->y);
}