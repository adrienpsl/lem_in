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

/*------------------------------------*\
    changer le fd dans les functions
\*------------------------------------*/

#include "../includes/all_includes.h"

/*
**    get le bon nb de fourmis
*/
void get_nb_foumis(t_getter get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line);
	if (is_int(get->utils.line, &result) == FAIL || result <= 0)
		ft_error("Il n'y a pas de fourmis OU le nb n'est pas Valable");
	get->data.nb_fourmis = result;
}

// premiere fonction get sur gnl les data
void lem_read_line()
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data.room = new_dll();
	get.data.tunnel = new_dll();

	get.utils.fd = open_file(
	 "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2");
	get_nb_foumis(&get);

	get_coord_room(&get);
	check_err_room(&get.data);

	get_tunnel(&get);

	ft_printf("list \n");
	dll_func(get.data.room, &print_room);

	ft_printf("start \n");
	print_room(get.data.start);
	ft_printf("end \n");
	print_room(get.data.end);

	dll_func(get.data.tunnel, &print_tunnel);


	// nb de salle,
	// le ration entre les sallw
	free_str(&get.utils.line);
}
