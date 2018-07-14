/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_includes.h"

int is_close_path(t_dll_l link, void *name_end_room)
{
	if (((t_path)link->content)->room
		==
		*(int *) name_end_room)
		return (TRUE);
	return (FALSE);
}

void drop_finish_path_working(t_finder finder)
{
	t_dll_l link_droped;


	while (dll_find_and_drop(finder->working_path,
							 is_close_path,
							 &finder->end_room,
							 &link_droped))
	{
		dll_add(link_droped,
				finder->close_path);
	}
}

/*------------------------------------*\
    enleve et met les path terminer dans la close liste
    working path = new_path
\*------------------------------------*/
int clean_woking(t_finder finder)
{
	finder->option = TRUE;
	//	dll_func(finder->new_path, print_path_dll);
	destroy_dll_func(&finder->working_path, dll_l_notfree_content);
	finder->working_path = finder->new_path;
	drop_finish_path_working(finder);
	option_print_list(finder, finder->working_path,
					  "path en cours de recherche");
	option_print_list(finder, finder->close_path,
					  "path finish");
	finder->new_path = new_dll();
	return (FALSE);
}