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

#ifndef ARGV_H
# define ARGV_H
# include <ntsid.h>

# define GNL_BUFF 512

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	int				r_stt;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_str_split
{
	char			**start;
	char			*current;
	int				where;
	int				all;
}					t_str_split_00;
typedef t_str_split_00	*t_str_split;

int					get_next_line(const int fd, char **line);
int					ft_error(char *str);
int					open_file(char *name);
int					ask_gnl(int fd, char **line, size_t *nb_line_ptr);
t_str_split			new_str_split(char *str, char c);
int					str_split_get(t_str_split split);
void				raise_errno(void *ptr);
void				destroy_str_split(t_str_split *split_ptr);

/*
**    error funtion
*/
void				errno_exit();

#endif
