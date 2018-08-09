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

t_debug_struct DEBUG;

t_debug_struct set_debug()
{
	t_debug_struct db;

	db = ft_0_new_memory(sizeof(t_debug_struct_00));
	(void)"  set les demandes de debug  ";
	db->parseur = TRUE;

	(void)"  set le fichier a check  ";
	db->str_file = "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2";


	DEBUG = db;
	return (db);
}


