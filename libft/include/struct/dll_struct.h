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

#ifndef DLL_STRUCT_H
# define DLL_STRUCT_H

# include "../dll_l_header.h"

typedef struct	s_dll_00
{
	size_t		length;
	t_dll_l		top;
	t_dll_l		where;
	t_dll_l		end;
}				t_dll_00;

typedef t_dll_00 *t_dll;

#endif
