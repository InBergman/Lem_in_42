/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:10:05 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 12:30:09 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef	struct	s_way
{
	char			*call;
	int				ants_number;
	unsigned int	hight;
	int				set_step;
	struct s_way	*next;
	struct s_way	*prev;
}				t_way;

typedef	struct	s_links
{
	char			*call;
	struct s_links	*next;
}				t_links;

typedef struct	s_arcs
{
	char			*name_call;
	int				set_ip;
	unsigned int	set_estimate;
	int				set_define;
	int				pos_x;
	int				pos_y;
	int				set_final;
	int				set_begining;
	int				set_old_ip;
	int				occupied;
	int				set_way;
	int				set_step;
	int				*is_neighbour;
	struct s_arcs	*next;
}				t_arcs;

typedef struct	s_all
{
	int				ants_number;
	int				let_shoot;
	int				select_number;
	int				bonus;
	int				turn;
	int				actions;
	unsigned int	division_set;
	t_arcs			*arcs;
	t_arcs			*set_begining;
	t_arcs			*set_final;
	t_way			*way;
	t_links			*links;
}				t_all;

void			init_var(t_all *basic);
int				is_space(char *str, int i);
void			set_empty(char **str);
int				do_touch(char *str, int i);
char			*join_free(char *argv, char str);
int				read_standard_input(char **argv);
int				check_start(t_all *all);
int				set_sommet(t_links **let_begin, char **str);
int				check_arcs_coordinates(char *s, int *i, \
				t_arcs **fresh, char next_char);
int				is_associable(t_all *all, t_arcs **fresh, int i);
int				get_arcs_values(t_arcs **fresh, char **str, int i);
int				set_plus_arcs(t_all *all, char **str, \
				int *begining, int *final);
int				check_arcs(t_all *all, char **str, int begening, int final);
t_arcs			*looking_for_arc(t_arcs **start, char *str, int i, int choice);
int				plus_neighbour(t_arcs *arcs, int ip);
int				check_neighboor(t_arcs **start, char *str, int i);
int				get_neighbour(t_all *all, char **str, int i);
t_arcs			*ft_lawer_value(t_arcs **starter);
int				ft_end_value(t_arcs **starter, t_arcs *new_element, int i);
int				second_parse_lower(t_arcs **starter, \
				t_arcs *new_element, int i);
int				to_delete(t_all *all);
int				ft_find_way(t_all *all);
int				reboot_arc(t_all *all);
t_way			*add_new_way(t_all *all, t_arcs *new_element, int i);
void			ft_init_end_to_start(t_all *all, int i);
t_way			*ft_put_last_way(t_all *all, t_arcs *new_element, int i);
int				ft_way_backup(t_all *all, t_arcs *browse);
int				manage_ants_sent(t_all *all, int actions);
int				manage_ant(t_all *all, int i);
void			ft_dijkstra(t_all *all, int i);
void			print_init(t_links **starter);
void			print_algo(int ant, char *name, int moved);
void			free_links(t_links **start);
void			free_arcs(t_arcs **start);
void			free_way(t_way **start);
int				free_all(t_all *all);

#endif
