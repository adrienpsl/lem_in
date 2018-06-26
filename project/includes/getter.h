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

#include "all_includes.h"

#ifndef GETTER_H
# define GETTER_H


/*
**    data
*/
typedef struct		s_get_data_00
{
	t_dll room;
	t_dll tunnel;
	t_dll_l start;
	t_dll_l end;
	int x;
	int y;
	int nb_fourmis;
} 					t_get_data_00;
typedef t_get_data_00 *t_get_data;

/*
**    utils
*/
typedef struct		s_get_utils_00
{
	int fd;
	int type_salle;
	char *line;

} 					t_get_utils_00;
typedef t_get_utils_00 *t_get_utils;


/*
**    getter
*/
typedef struct		s_getter_00
{
	t_get_data_00 data;
	t_get_utils_00 utils;
} 					t_getter_00;
typedef t_getter_00 *t_getter;

#endif //LEM_IN_GETTER_H
