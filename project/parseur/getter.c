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

//// fonction pour gere les erreur
// tester pk mon atoi deconne
void get_fufu(t_getter get)
{
	ask_gnl(get->utils.fd, &get->utils.line);
	get->data.nb_fourmis = ft_atoi(get->utils.line);
	if (get->data.nb_fourmis <= 0)
		ft_error("il n'y a pas de fourmis ou le nb n'est pas valable");
}

// fonction qui gere premiere vague
// stock les coord dans une list

void manage_comment(t_get_utils utils)
{

	if (utils->split->current[0] == '#' ||
		utils->split->current[0] == 'l')
		if (ft_strcmp(utils->line, "##start") == 0)
			utils->tmp = L_START;
		else if (ft_strcmp(utils->line, "##end") == 0)
			utils->tmp = L_END;
}

void get_room(t_getter get)
{
	static t_dll_l room_link = NULL;
	static t_str_split split;

	split = get->utils.split;
	room_link = new_room_link(split->current,
							  split->current + 1,
							  split->current + 2);
	// doit mettre le bon truc

	dll_add(room_link, get->data.room);

	//
}

void get_coord_room(t_getter get)
{
	static t_get_utils utils;

	utils = &get->utils;
	while (ask_gnl(utils->fd, &utils->line))
	{
		utils->split = new_str_split(utils->line, ' ');
		// get room
		if (utils->split->all == 3)
			get_room(get);

			// stop next serie
		else if (utils->split->all == 2)
			break;

			//get comment
		else if (utils->split->all == 1)
			manage_comment(get);

		else
			ft_error("err dans les salles mechant");


		// clear split
	}
}
// fonction qui gere deuxieme vague

//



// premiere fonction get sur gnl les data
void lem_read_line()
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));

	get.utils.fd = open_file(
	 "/Users/adpusel/Dropbox/42/projects/lem_in/project/test/test_2");
	get_fufu(&get);
	get_coord_room(&get);
	free_str(&get.utils.line);
}
