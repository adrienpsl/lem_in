/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_l_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:31:01 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_HEADER_H
# define ERR_HEADER_H

typedef struct		s_err1_00
{
	int				is_error;
	t_dll			list_error;
}					t_err1_00;
typedef t_err1_00 *t_err1;

typedef struct		s_err1_link_00
{
	int				code_err;
	char			*name_err;
	char			*where_err;
}					t_err1_link_00;
typedef t_err1_link_00 *t_err1_link;

void				new_error_1(t_err1 err, char *str_err, int code_err);
t_err1				new_err1();
void				destroy_err1(t_err1 err1);
void				err1_print_err(t_err1 err1);
void				err1_add_err(t_err1 err1, char *name_err, int code_err,
	char *where_err);

int					print_err_retrun_int(char *err_name, int display);
void				*print_err_retrun_null(char *err_name, int display);

#endif
