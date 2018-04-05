/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:31:35 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:24 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

int			set_sommet(t_links **let_begin, char **str)
{
	t_links	*is_first;
	t_links	*is_second;

	is_second = *let_begin;
	if (!(is_first = (t_links*)malloc(sizeof(*is_second))))
	{
		ft_strdel(str);
		return (0);
	}
	is_first->next = NULL;
	if (!(is_first->call = ft_strdup(*str)))
	{
		ft_strdel(str);
		return (0);
	}
	ft_strdel(str);
	if (!is_second)
		*let_begin = is_first;
	else
	{
		while (is_second->next)
			is_second = is_second->next;
		is_second->next = is_first;
	}
	return (1);
}

static int	empty_ret(char **str, int i)
{
	set_empty(str);
	return (i);
}

int			check_start(t_all *all)
{
	char	*str;

	str = NULL;
	if (read_standard_input(&str) <= 0)
		return (empty_ret(&str, -1));
	if (spe_atoi_mod(str, &(all->ants_number)) < 0)
		return (empty_ret(&str, -1));
	else if (!set_sommet(&(all->links), &str))
		return (-2);
	if (check_arcs(all, &str, 0, 0) < 0)
		return (empty_ret(&str, -3));
	if ((!all->set_begining || !all->set_final))
		return (empty_ret(&str, -4));
	if (get_neighbour(all, &str, 0) < 0)
		return (empty_ret(&str, -5));
	return (1);
}
