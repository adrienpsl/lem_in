/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
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
#include "../../libft/include/dll_header.h"
#include "struct_min.h"
#include "struct_algo.h"

/*
**    lem ========================================================
*/
typedef struct s_lem
{
	t_data data;
	t_algo algo;
} t_lem_00;

typedef t_lem_00 *t_lem;

/*
**    struct_path
*/
typedef struct		s_b_path_00
{
	char *tab;
	int nb;
	int line;
} 					t_b_path_00;
typedef t_b_path_00 *t_b_path;


/*
**    best_path ========================================================
*/
typedef struct s_best_path_00
{
	t_b_path_00 cache;
	t_b_path_00 data;

} t_best_path_00;

typedef t_best_path_00 *t_best_path;

/*
**    real_path ========================================================
*/
typedef struct s_real_path_00
{
	int size;
	int free;
	t_dll list_path;
} t_real_path_00;

typedef t_real_path_00 *t_real_path;

typedef struct		s_move_00
{
	t_data	data;
	int nb_fourmis;
	size_t size_tab;
	t_real_path *tab;
	int end_room;
} 					t_move_00;
typedef t_move_00 *t_move;

#endif
