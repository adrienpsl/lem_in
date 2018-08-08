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

#include "../all_includes.h"
extern t_debug_struct DEBUG;


/*
**	**** VARIABLES
**
**	**** RETURN
**
**	**** MAKING
**  set le nb de fourmis et verifie qu'il est un int
*/
void get_nb_foumis(t_getter get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line);
	if (str_is_int(get->utils.line, &result) == FAIL || result <= 0)
		ft_error("Il n'y a pas de fourmis OU le nb n'est pas Valable");
	get->data->nb_fourmis = result;
	free_str(&get->utils.line);
}

/*
**	**** VARIABLES
**	data	> sock toute les data du parseur
**
**	**** RETURN
**
**	**** MAKING
*/
void lem_getter(t_data data)
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data = data;

	get.utils.fd = open_file(DEBUG->str_file);

	get_nb_foumis(&get);
	get_room(get.data, &get.utils);
	get_tunnel(get.data, &get.utils);
}

/*!
 * 	le parseur va get toute les err et lees stoker au fur et a mesure
 * 	si err, le parseur les print et quitte
 */
void read_and_parse_data(t_lem lem)
{
	t_data data;

	data = ft_0_new_memory(sizeof(t_data_00));
	data->room = new_dll();
	data->tunnel = new_dll();

	lem_getter(data);
	// si une err je quite en la printant --> si plusieur err je dois avoir un tab qui les listes >
	lem->data = data;
}
