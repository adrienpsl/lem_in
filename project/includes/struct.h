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

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

#include "getter.h"
#include "../libft/include/dll_header.h"
#include "struct_min.h"
#include "struct_algo.h"

/*
**    lem ========================================================
*/
typedef struct s_lem
{
	t_data data;
	t_algo_00 algo;
} t_lem_00;

typedef t_lem_00 *t_lem;


/*
**    best_line ========================================================
*/
typedef struct		s_best_path_00
{
	char *cur_tab_good_path;
	int nb_independant_path;
	char *tab_good_path;
	int good_path_nb;
	int best_line;
} 					t_best_path_00;
typedef t_best_path_00 *t_best_path;


/*
**    move_lem ========================================================
*/
typedef struct		s_move_00
{
	t_map	map;
	char 	*tab_best_path;
	t_data 	data;
} 					t_move_00;
typedef t_move_00 *t_move;



#endif
