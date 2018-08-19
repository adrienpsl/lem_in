/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include "stdio.h"

typedef struct		s_vt_00
{
	size_t			size;
	void			**tab;
}					t_vt_00;
typedef t_vt_00 *t_vt;

/*
**    contruct ========================================================
*/
t_vt				new_void_tab(size_t size_tab);
void				destruct_v_tab(t_vt *tab_ptr);

/*
**    function ========================================================
*/

/*
**    getter
*/
void				vt_get_dll(t_vt tab_ptr, t_dll list);

/*
**    DEBUG ========================================================
*/
void				vt_print_func(t_vt tab_ptr, int (*func)(void*, void*),
	void *ptr);

#endif
