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


t_dll_l get_tunnel(t_str_split split, t_get_data data,)
{

}



// fonction qui gere deuxieme vague
/*------------------------------------*\
    surveiller que ce soit bien des nb,
    et que j'ai bien des rooms qui matche avec ca
    esquiver les commentaires

\*------------------------------------*/
void get_tunnel(t_getter get)
{
	static t_get_utils utils;
	static t_dll_l tunnel_link;
	t_str_split split;

	split = NULL;
	utils = &get->utils;
	while (ask_gnl(utils->fd, &utils->line))
	{
		split = new_str_split(utils->line, ' ');
		if (split->current[0] == '#')
			utils->type_salle = manage_comment(split);
		else if (split->all == 2)
		{
//			room_link = get_room(split, &get->data, &get->utils);
//			if (room_link == NULL)
//				ft_error("err dans un link");
//			else
//				dll_add(room_link, get->data.room);
		}
		else
			break;
		destroy_str_split(&split);
	}
	destroy_str_split(&split);
}


// premiere fonction get sur gnl les data
void lem_read_line()
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data.room = new_dll();
	get.data.connextion = new_dll();


	get.utils.fd = open_file(
	 "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2");
	get_nb_foumis(&get);

	get_coord_room(&get);
	check_err_room(&get.data);


	ft_printf("list \n");
	dll_func(get.data.room, &print_room);

	ft_printf("start \n");
	print_room(get.data.start);
	ft_printf("end \n");
	print_room(get.data.end);

	free_str(&get.utils.line);
}
