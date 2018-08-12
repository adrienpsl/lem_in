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

#include "../includes/all_includes.h"

t_best_path new_best_path(size_t nb_path)
{
	t_best_path best;
	t_b_path cache;

	best = ft_0_new_memory(sizeof(t_best_path_00));
	cache = &best->cache;
	cache->tab = ft_0_new_memory(sizeof(char) * nb_path);
	//	cache->nb = 1;
	//	print_line_first_int(best->tab_good_path, nb_path, 0);
	//	print_line_first_int(best->cur_tab_good_path, nb_path, 0);
	return (best);
}