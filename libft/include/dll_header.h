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

#ifndef DLL_HEADER_H
# define DLL_HEADER_H

# include <stdlib.h>
# include "dll_l_header.h"
# include "dll_c_header.h"
# include "align.h"

/*
**    structure
*/
# include "struct/dll_struct.h"

/*
**    construct ================================================================
*/
t_void___	destroy_dll(t_dll *dll);
t_void___	destroy_dll_func(t_dll *l, void (*func)(void *));
t_dll		new_dll();

/*
**    method ===================================================================
*/

/*
**    add link
*/
t_dll_l		dll_add(t_dll_l link, t_dll list);
t_dll_l		dll_push(t_dll_l link, t_dll list);
t_dll_l		dll_add_at_index(t_dll_l link, t_dll list, size_t index);

/*
**    add and create
*/
t_dll_l		dll_ptr_add_create(void *link, t_dll list);

/*
**    drop link
*/
t_dll_l		dll_drop_link(t_dll list, t_dll_l link);
t_dll_l		dll_drop_end(t_dll list);
t_dll_l		dll_drop_top(t_dll list);
t_dll_l		dll_drop_index(t_dll list, size_t index);

int			dll_find_and_drop(t_dll list, int (*func)(t_dll_l, void *),
	void *ptr,
	t_dll_l *link_out);

int			dllwhere_find_and_drop(t_dll list, int (*func)(t_dll_l, void *),
	void *ptr,
	t_dll_l *link_out);

/*
**    delete link
*/
int			dll_delete_link(t_dll list, t_dll_l link);

/*
**    find link
*/
t_void___	dll_func_lim(t_dll lst, int lim, void (*func)(t_dll_l));
t_int____	dll_func_ret(t_dll lst, int (*func)(t_dll_l));
t_dll_l		dll_find(t_dll list, int(*func)(t_dll_l, void *), void *ptr);

t_dll_l		dll_find_index(t_dll list, int (*func)(t_dll_l, void *), void *ptr,
	size_t *index_ptr);

t_int____	dll_index_link(t_dll_l link_searched, t_dll list, size_t
*index_ptr);

t_int____	dll_index_link_func(t_dll list, int(*func)(t_dll_l, void *),
	void *ptr,
	size_t *index_ptr);

/*
**    utils ====================================================================
*/
t_dll_l		dll_list_empty(t_dll_l link, t_dll list);
t_dll_l		dll_drop_list_one(t_dll list);
t_dll_l		get_good_link(size_t index, t_dll list);

/*
**    debug ====================================================================
*/
t_void___	dll_func(t_dll lst, void(*func)(void *));
void		dll_func_where(t_dll lst, void (*func)(t_dll_l));

/*
**    depreciate
*/
t_void___	dll_fill_list_circular(t_dll_c c_list,
	t_dll list, size_t lenght);
t_void___	dll_print_nb(t_dll lst);
t_void___	dll_print_nbrev(t_dll lst);
t_void___	dll_print_str(t_dll lst);
t_void___	dll_print_strrev(t_dll lst);

#endif
