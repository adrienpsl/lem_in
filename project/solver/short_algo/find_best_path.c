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
    va passer comparer avec tous les path deja tester et independant pour savoir
    si le current path est bien independant

    verifie que les chemin deja touver son independant du nouveau
\*------------------------------------*/
int check_all_case(char *tab_path_deja_trouve, char *test_line, t_map map)
{
	size_t i;

	i = 0;
	while (i < map->line)
	{
		if (tab_path_deja_trouve[i] == 1)
		{
			if (cmp_line(map->start + (i * map->line), test_line, map->line))
				return (TRUE);
		}
		i++;
	}
	//	printf("ok \n");
	return (FALSE);
}

//void     is_bettre_best_path(t_best_path best)
//{
//    if(bes)
//}

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
    pour le moment ca ne me test que le premier
\*------------------------------------*/
void find_best_path(t_map map, t_best_path best_path)
{
	size_t line;
	char *test_line;

	line = 0;
	//	printf(" \n");
	//	print_line(map->start + (cur_line * map->line), map->line, 1);
	//	printf(" \n");
	print_line(map->start, map->line, 0);

	while (line < map->line)
	{
		test_line = map->start + (line * map->line);
		// je dois tester tout les autres chemin
		if (check_all_case(best_path->tab_current, test_line, map) ==
			FALSE)
		{
			print_line(map->start + (line * map->col), map->col, 1);
			//			printf("%d \n", best_path->max_founded);
			++best_path->nb_current;
			best_path->tab_current[line] = 1;
			// faire une mise a jour du best path 
		}
		++line;
	}
//	print_line_first(best_path->tab_current)
}

