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

#ifndef LEM_IN_FUNCTION_H
# define LEM_IN_FUNCTION_H

# include "all_includes.h"
/*
**   PARSEUR  ========================================================
*/
void	lem_read_line();
void	get_coord_room(t_getter get);


/*
**    paseur utils
*/
int		manage_comment(t_str_split split);
int		is_right_room(t_dll_l link, void *ptr_new_room);
void	check_err_room(t_get_data data);


#endif //LEM_IN_FUNCTION_H