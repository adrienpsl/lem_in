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
    faux si les deux ligne sont vide au meme endroit
\*------------------------------------*/
int cmp_line(char *cur_line, char *line, size_t lim)
{
	size_t i;

	i = 0;
	while (i < lim)
	{
		if (cur_line[i] && line[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

/*------------------------------------*\
	return le nombre de chemin entierement different du path que j'envoie
 	et les print dans best path
\*------------------------------------*/
void test_current_path(t_map map, t_best_path best_path, int cur_ligne)
{
	size_t i;

	i = 0;
	while (i < map->line)
	{
		if (cmp_line(map->start + (i * map->line),
					 map->start + (i * cur_ligne),
					 map->col))
		{
			best_path->cur_good_path[i] = TRUE;
		}
		i++;
	}
	//	printf("ok \n");
}

/*
**	**** VARIABLES
**	cur_line	> 	la ligne en cours de test de la map de tout les chemins
**
**	**** RETURN
**
**	**** MAKING
**	si diff_path( nombre de path independent de best_path) < test actuel
**		le best_path garde la ligne en cours
**		je transfere le tab des paths independant dans le cache
**		je reset le cache
*/

void is_bettre_best_path(t_best_path best, int cur_line)
{
	if (best->diff_path < best->cur_nb)
	{
		best->best_path = cur_line;
		free_str(&best->good_path);
		best->good_path = best->cur_good_path;
		best->diff_path = best->cur_nb;
		best->cur_nb = 0;
	}
}

/*
**	**** VARIABLES
**	map			>	all_path x nb_room
**	best_path	> 	save le nb de path different compatible d'in path avec un autre
**
**
**	**** RETURN
**	=> le best past
**
**	**** MAKING
**	genere le best_path, que apres je set dedans
*/

/*------------------------------------*\
   je passe sur chaque ligne et je get celui qui a le plus de
   connection possible, et je selectinne tout les chemin ok


\*------------------------------------*/
void find_best_path(t_map map, t_best_path best_path)
{
	size_t line;

	line = 0;
	//	printf(" \n");
	//	print_line(map->start + (cur_line * map->line), map->line, 1);
	//	printf(" \n");
	print_line(map->start, map->line, 0);

	while (line < map->line)
	{
		test_current_path(map, best_path, line);
		//			print_line(map->start + (line * map->col), map->col, 1);
		is_bettre_best_path(best_path, line);
		++line;
	}
		print_line_first(best_path)
}

