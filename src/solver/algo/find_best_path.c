/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:46:36 by mipham            #+#    #+#             */
/*   Updated: 2018/08/17 15:51:42 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/all_includes.h"

int		cmp_line(char *cur_line, char *line, size_t lim)
{
	size_t	i;

	i = 0;
	if (cur_line == line)
		return (TRUE);
	while (i < lim)
	{
		if (cur_line[i] && line[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

int		test_prev_good_path(t_map map, t_b_path cache, int cur_line)
{
	size_t		col;

	col = 0;
	while (col < map->col)
	{
		if (cache->tab[col] == TRUE)
		{
			if (cmp_line(map->map + (col * map->col),
						map->map + (cur_line * map->col), map->col) == TRUE)
				return (FALSE);
		}
		++col;
	}
	return (TRUE);
}

/*
**	return le nombre de chemin entierement different du path que j'envoie
** 	et les print dans best path
** 	les path doivents aussi etre differents des path deja get
*/

void	test_current_path(t_map map, t_b_path cache, int cur_line)
{
	size_t	line;

	line = 0;
	while (line < map->line)
	{
		if (cmp_line(map->map + (line * map->col),
					map->map + (cur_line * map->col), map->col) == FALSE
				&& test_prev_good_path(map, cache, line) == TRUE)
		{
			cache->tab[line] = TRUE;
			cache->nb += 1;
		}
		line++;
	}
}

/*
**	**** VARIABLES
**	cur_line	> 	la ligne en cours de test de la map de tout les chemins
**
**	**** RETURN
**
**	**** MAKING
**	si good_path_nb( nombre de path independent de best_line) < test actuel
**		le best_line garde la ligne en cours
**		je transfere le tab des paths independant dans le cache
**		je reset le cache
*/

void	is_bettre_best_path(t_best_path best, int cur_line, size_t nb_path)
{
	t_b_path	cache;
	t_b_path	data;

	cache = &best->cache;
	data = &best->data;
	if (data->nb < cache->nb)
	{
		data->line = cur_line;
		free_str(&data->tab);
		data->tab = cache->tab;
		cache->tab = ft_0_new_memory(sizeof(char) * nb_path);
		data->nb = cache->nb;
	}
	cache->nb = 0;
}

void	find_best_path(t_map map, t_best_path best)
{
	size_t		line;

	line = 0;
	while (line < map->line)
	{
		test_current_path(map, &best->cache, line);
		best->cache.nb++;
		is_bettre_best_path(best, line, map->line);
		best->data.tab[best->data.line] = TRUE;
		++line;
	}
	if (DEBUG->map_path)
	{
		ft_printf("----> les chemins independants \n");
		print_line_first_int(best->data.tab, map->line, 0);
		ft_printf("---- \n");
	}
}
