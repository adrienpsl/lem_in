#include <stdio.h>
#include "project/includes/function.h"


t_lem new_lem()
{
	t_lem lem;

	lem = ft_malloc_protect(sizeof(t_lem_00));
	ft_bzero(lem, sizeof(t_lem_00));
	lem->algo00.all_path = new_dll();
	return (lem);
}

// je creer la premiere liste chainee, celle du depart
// je parcours les connection de

//void for_all(t_path path, t_dll all_path)
//{
//	// je parcours les link de la liste
//}

int main()
{
	t_lem lem;
	t_path first;
	t_dll_l path_link;
	t_data_00 *data;


	first = new_dll();
	path_link = new_dll_l_ptr();
	path_link->content = first;

	lem = new_lem();
	lem->data = lem_read_line(NULL);
	data = &lem->data;
	

	print_room(data->start);


	return 0;
}