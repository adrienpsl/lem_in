/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:01:15 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:01:51 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all_includes.h"

t_best_path		new_best_path(size_t nb_path)
{
	t_best_path		best;
	t_b_path		cache;

	best = ft_0_new_memory(sizeof(t_best_path_00));
	cache = &best->cache;
	cache->tab = ft_0_new_memory(sizeof(char) * nb_path);
	return (best);
}
