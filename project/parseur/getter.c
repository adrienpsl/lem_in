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

/*
**	**** VARIABLES
**
**	**** RETURN
**
**	**** MAKING
**  set le nb de fourmis et verifie qu'il est un int
*/
int get_nb_foumis(t_getter get)
{
	static int result = 0;

	ask_gnl(get->utils.fd, &get->utils.line, NULL);
	if (str_is_int(get->utils.line, &result) == FAIL)
		err1_add_err(get->utils.err,
					 ERR_FOURMIS_1,
					 0, NULL);
	else if (result <= 0)
		err1_add_err(get->utils.err,
					 ERR_FOURMIS_2,
					 0, NULL);
	get->data->nb_fourmis = ft_atoi(get->utils.line);
	/*------------------------------------*\
	    data printed
	\*------------------------------------*/
	if (DEBUG->parseur == TRUE)
		printf("---> nb fourmis : %d\n---- \n", get->data->nb_fourmis);
	return (get->utils.err->is_error == FALSE ? TRUE : FALSE);
}

/*
**	**** VARIABLES
**	data	> sock toute les data du parseur
**
**	**** RETURN
**
**	**** MAKING
*/

int lem_getter(t_data data)
{
	t_getter_00 get;

	ft_memset(&get, 0, sizeof(t_getter_00));
	get.data = data;

	(void) "  je set utils  ";
	get.utils.err = new_err1();
	get.utils.fd = open_file(DEBUG->str_file);

	// toute les fonctions retourn ret ==> qui represente les erreur
	// mes err --> nom de l'erreur, son type, sa ligne
	if (
	 get_nb_foumis(&get) == TRUE &&
	 get_room(get.data, &get.utils) == TRUE &&
	 check_err_room(data) == TRUE
//	 &&
//	 get_tunnel(data, &get.utils) == TRUE
		)
		return (TRUE);
	err1_print_err(get.utils.err);
	err1_print_err(get.utils.err);

	return (FALSE);
}

/*!
 * 	le parseur va get toute les err et lees stoker au fur et a mesure
 * 	si err, le parseur les print et quitte
 */
int read_and_parse_data(t_lem lem)
{
	t_data data;
	int ret = 0;

	data = ft_0_new_memory(sizeof(t_data_00));
	data->room = new_dll();
	data->tunnel = new_dll();
	data->start_room = -1;
	data->end_room = -1;

	ret = lem_getter(data);
	//	if (lem_getter(data) == FALSE)
	// si une err je quite en la printant --> si plusieur err je dois avoir un tab qui les listes >
	lem->data = data;
	return (ret);
}
