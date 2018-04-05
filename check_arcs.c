/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:43:19 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:30 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

int		is_associable(t_all *all, t_arcs **f, int i)
{
	t_arcs	*t;
	t_arcs	*tmp2;

	t = all->arcs;
	tmp2 = NULL;
	while (i >= 0 && t && ++i)
	{
		tmp2 = t;
		(t->set_begining && (*f)->set_begining) ? i = -1 : 0;
		(t->set_final && (*f)->set_final) ? i = -1 : 0;
		(ft_strequ((*f)->name_call, t->name_call)) ? i = -1 : 0;
		((*f)->pos_x == t->pos_x && (*f)->pos_y == t->pos_y) ? i = -1 : 0;
		t = t->next;
	}
	if (i < 0)
	{
		ft_strdel(&((*f)->name_call));
		free((*f));
		(*f) = NULL;
		return (-2);
	}
	(*f)->set_ip = (!tmp2) ? 1 : i + 1;
	(tmp2) ? tmp2->next = (*f) : 0;
	(!tmp2) ? all->arcs = (*f) : 0;
	return (1);
}

int		check_arcs_coordinates(char *s, int *i, t_arcs **fresh, char next_char)
{
	int		nb;
	int		j;
	int		sign;

	nb = 0;
	sign = (s[*i] == '-' && ft_isdigit(s[*i + 1]) && (*i += 1)) ? 1 : 0;
	*i += (s[*i] == '+' && ft_isdigit(s[*i + 1])) ? 1 : 0;
	j = (s[*i]) ? 1 : -1;
	while (j == 1)
	{
		if (nb == 214748364 && ((sign && s[*i] > 56) || (!sign && s[*i] > 55)))
			j = -2;
		else if (s[*i] < 48 || s[*i] > 57 || nb > 214748364)
			j = -2;
		else
		{
			nb = nb * 10 + s[*i] - 48;
			++(*i);
		}
	}
	(sign) ? nb = -nb : 0;
	(next_char == ' ') ? (*fresh)->pos_x = nb : 0;
	(next_char == '\0') ? (*fresh)->pos_y = nb : 0;
	(j == -2 && s[*i] == next_char && ++(*i)) ? j = 0 : 0;
	return (j);
}

int		get_arcs_values(t_arcs **fresh, char **str, int i)
{
	while (str[0][i] && str[0][i] != ' ')
		i++;
	if (!str[0][i] || i == 0 || !((*fresh)->name_call = ft_strsub(*str, 0, i)))
		return (-1);
	i++;
	if (!str[0][i])
		return (-1);
	if (check_arcs_coordinates(*str, &i, fresh, ' ') < 0)
		return (-1);
	if (check_arcs_coordinates(*str, &i, fresh, '\0') < 0)
		return (-1);
	(*fresh)->occupied = 0;
	(*fresh)->next = NULL;
	(*fresh)->set_estimate = -1;
	(*fresh)->set_define = 0;
	(*fresh)->set_way = 0;
	(*fresh)->is_neighbour = NULL;
	return (i);
}

int		set_plus_arcs(t_all *all, char **str, int *begining, int *final)
{
	t_arcs	*fresh_arc;
	int		i;

	i = 0;
	fresh_arc = NULL;
	if (!(fresh_arc = (t_arcs*)malloc(sizeof(*fresh_arc))))
		return (-1);
	if (get_arcs_values(&fresh_arc, str, 0) < 0)
	{
		if (fresh_arc->name_call)
			ft_strdel(&(fresh_arc->name_call));
		free(fresh_arc);
		fresh_arc = NULL;
		return (-2);
	}
	fresh_arc->set_begining = *begining;
	(*begining) ? all->set_begining = fresh_arc : 0;
	*begining = 0;
	fresh_arc->set_final = *final;
	(*final) ? all->set_final = fresh_arc : 0;
	*final = 0;
	return (is_associable(all, &fresh_arc, i));
}

int		check_arcs(t_all *all, char **str, int begening, int final)
{
	while (1)
	{
		if (read_standard_input(str) < 0 || !(*str))
			return (-1);
		else if (str[0][0] == '#')
		{
			(ft_strequ("##start", *str)) ? begening = 1 : 0;
			(ft_strequ("##end", *str)) ? final = 1 : 0;
		}
		else if (str[0][0] == 'L' || str[0][0] == ' ')
			return (-2);
		else if (!is_space(*str, 0) || do_touch(*str, -1))
			break ;
		else if (set_plus_arcs(all, str, &begening, &final) < 0)
			return (-3);
		if (!set_sommet(&(all->links), str))
			return (-4);
	}
	return ((final || begening) ? -2 : 1);
}
