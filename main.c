#include <stdio.h>
#include "project/includes/function.h"

/*------------------------------------*\
    faux si les deux ligne sont vide au meme endroit
\*------------------------------------*/
int cmp_line(char *cur_line, char *line, size_t lim)
{
	size_t i;

	i = 0;
	while (i < lim)
	{
		if (cur_line[i] && line[i])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

/*------------------------------------*\
    va passer comparer avec tous les path deja tester et independant pour savoir
    si le current path est bien independant

    verifie que les chemin deja touver son independant du nouveau
\*------------------------------------*/
int check_all_case(char *tab_path_deja_trouve, char *test_line, t_map map)
{
	size_t i;

	i = 0;
	while (i < map->line)
	{
		if (tab_path_deja_trouve[i] == 1)
		{
			if (cmp_line(map->start + (i * map->line), test_line, map->line))
				return (TRUE);
		}
		i++;
	}
//	printf("ok \n");
	return (FALSE);
}


// il me faut une structure avec un tab oour chaqun et un tab d'in qui me stoque
// les resultats pour chacun
/*------------------------------------*\
    creer un tab qui possede le chemin en test
    et tout les autres chemin tester qui sont independants de lui et deja comparer

 	i = line deja parcouru dans le tab de test

 	pour chaque chemin pris en repere, combien de chemin possible reste t il

\*------------------------------------*/
void test_un_chemin(size_t cur_line_nb, t_map map, t_best_path path)
{
	size_t col;
	char *test_line;

	(void)cur_line_nb;
	col = 0;

//	printf(" \n");
//	print_line(map->start + (cur_line_nb * map->col), map->line, 1);
//	printf(" \n");


	while (col < map->col)
	{
		test_line = map->start + (col * map->line);
		// je dois tester tout les autres chemin
		if (check_all_case(path->tab_current, test_line, map) ==
			FALSE)
		{
//			print_line(map->start + (col * map->line), map->line, 1);
//			printf("%d \n", path->max_founded);
			++path->nb_current;
			path->tab_current[col] = 1;
		}
		++col;
	}
}

// liste chainer des chemins possibles que s'il y en a plus que le premiers
// je pars de la fin de la list, et des que il y a plus de chemin je remplace le
// tab definitif
/*------------------------------------*\
    parcours tout les chemins trouver dans la liste all_paths
    pour avoir une liste chainer des chemin independants les un des autres

    un tab pour mettre le nombre de chemin independants pour chaque chemin
\*------------------------------------*/

t_best_path new_best_path(size_t size)
{
	t_best_path path;
	path = ft_0_new_memory(sizeof(t_best_path_00));
	path->tab_current = ft_0_new_memory(sizeof(char) * size);
	path->tab_result = ft_0_new_memory(sizeof(char) * size);
	return (path);
}

void t_1(t_dll all_path_list, t_map map)
{
	t_dll list_out = new_dll();
	char *tmp;
	t_best_path path;
	size_t i;

	i = 0;
	path = new_best_path(map->line);
	(void) all_path_list;
	(void) list_out;

	path->tab_current[i] = 1;

	while (i < map->line)
	{
		test_un_chemin(i, map, path);
		if (path->nb_current > path->max_founded)
		{
			path->max_founded = path->nb_current;
			tmp = path->tab_current;
			path->tab_current = path->tab_result;
			path->tab_result = tmp;
//			printf("%d \n", path->max_founded);
		}
//		printf("---------------------------------------------- \n");
		ft_bzero(path->tab_current, map->line);
		++i;
	}
	print_line_path(path->tab_result, map->line);

}

int main()
{
	setbuf(stdout, NULL);
	t_lem lem;
	t_algo algo;
	t_finder cache;
	t_map map;

	t_dll list;

	(void) list;
	lem = new_lem();
	algo = &lem->algo;
	map = &algo->map;
	cache = &algo->cache;

		cache->option = TRUE;
	get_all_path(cache, map);

	/*------------------------------------*\
	    je print les paths et je relechis a comment leurs generer une start

	\*------------------------------------*/
//	dll_func(cache->close_path, print_path_dll);

	t_map_00 map_t1;
	generate_path_map(lem->data->room, cache->close_path, &map_t1);
	t_1(cache->close_path, &map_t1);
	// je copy chaque liste dans sont propre paht



	//	list = copy_all_path_order(cache->close_path->top);

	// je fait le trie dans les chemin
	//	printf("Inversion des path listes et transfere en liste chaine \n ---- \n");
	//	dll_func(list, print_list_dll_path);

	//	test_1(list->top, list);
	//	test_1(list->top->next, list);
	//	dll_func(list, print_list_dll_path);

	printf("%d \n", lem->data->lim);
	//	destroy_dll_func(&list, free_list_list_path);
	destroy_cache(&algo->cache);
	free_lem(lem);
	return EXIT_SUCCESS;
}