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

#include "../../all_includes.h"

/*------------------------------------*\
    il me faut : le tab des taken room,
    les trois liste pour gerer le cache
    la liste pour tout free

\*------------------------------------*/
t_finder
new_finder_big_algo(t_data data, int start_rom, t_map map, t_cache cache)
{
	t_finder finder;

	finder = ft_0_new_memory(sizeof(t_finder_00));
	finder->all_path = new_dll();
	finder->new_path = new_dll();
	finder->taken_room = ft_0_new_memory(sizeof(char) * data->room->length);
}
//	je repend le principe du cache,
// 	while working path
// 		stack --> working path, tout les chemin avancent d'une case
// 				en verifiant que la room n'est pas prise et que
t_move big_algo(t_cache cache, t_data data, t_map map)
{
	t_finder finder;
	//	t_map  path_map;
	//	t_move  move;


}
