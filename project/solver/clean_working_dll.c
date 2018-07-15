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

/*
**	**** VARIABLES
**
**	**** RETURN
**	=> TRUE si le path pointe sur la end room == le path est valide et terminé
**
**	**** MAKING
*/
int is_close_path(t_dll_l cur_link, void *name_end_room)
{
	if (((t_path)cur_link->content)->room
		==
		*(int *) name_end_room)
		return (TRUE);
	return (FALSE);
}

/*
**	**** VARIABLES
**	finder	> stocke le cache et les data de recherche de path
**
**	**** RETURN
**
**	**** MAKING
**	retire de finder->working_path touts les links (path) et les ajoutes
**	a finder->valid_path
**
*/
void drop_finish_path_working(t_finder finder)
{
	t_dll_l link_dropped;

	while (dll_find_and_drop(finder->working_path,
							 is_close_path,
							 &finder->end_room,
							 &link_dropped))
	{
		dll_add(link_dropped,
				finder->valid_path);
	}
}

/*
**	**** VARIABLES
**	finder	> stocke le cache et les data de recherche de path
**
**	**** RETURN
**
**	**** MAKING
**	free finder->working_path car tout ses maillons on ete check et lui assigne
**	new_path
**	drop avec -- drop_finish_path_working -- les valid_path
**	assigne une nouvelle list a new_path
*/
void clean_woking(t_finder finder)
{
	finder->option = TRUE;
	//	dll_func(finder->new_path, print_path_dll);
	destroy_dll_func(&finder->working_path, dll_l_notfree_content);
	finder->working_path = finder->new_path;
	drop_finish_path_working(finder);
	option_print_list(finder, finder->working_path,
					  "path en cours de recherche");
	option_print_list(finder, finder->valid_path,
					  "path finish");
	finder->new_path = new_dll();
}