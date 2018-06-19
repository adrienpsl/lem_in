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

# include "all_includes.h"
#include "../libft/include/dll_header.h"


/*
**    struct ========================================================
*/

/*
**    lem
*/
typedef struct		s_lem
{

}					*t_lem;

/*
**    getter
*/
typedef struct		s_getter_00
{
	int x;
	int y;
	int fufu;
	char *line;
	t_dll room;
	t_dll link;



} 					t_getter_00;
typedef t_getter_00 *t_getter;



/*
**    construct ================================================================
*/
void  destroy_lem(t_lem *lem);
t_lem new_lem();

/*
**    method ===================================================================
*/


/*
**    utils ====================================================================
*/

/*
**    debug ====================================================================
*/


#endif
