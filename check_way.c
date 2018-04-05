/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 14:15:52 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:19 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

t_arcs	*ft_lawer_value(t_arcs **starter)
{
	t_arcs			*tmp;
	t_arcs			*save;
	unsigned int	lowest;

	tmp = *starter;
	save = NULL;
	lowest = -1;
	while (tmp)
	{
		if (!tmp->set_define && tmp->set_estimate < lowest)
		{
			lowest = tmp->set_estimate;
			save = tmp;
		}
		tmp = tmp->next;
	}
	return (save);
}

int		ft_end_value(t_arcs **starter, t_arcs *new_element, int i)
{
	t_arcs			*tmp;

	while (++i < new_element->set_way)
	{
		tmp = *starter;
		while (tmp)
		{
			if (tmp->set_ip == new_element->is_neighbour[i] && tmp->set_final)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int		second_parse_lower(t_arcs **starter, t_arcs *new_element, int i)
{
	t_arcs	*tmp;

	if (ft_end_value(starter, new_element, -1))
		return (1);
	while (++i < new_element->set_way)
	{
		tmp = *starter;
		while (tmp)
		{
			if (tmp->set_ip == new_element->is_neighbour[i] \
				&& !tmp->set_define && \
			tmp->set_estimate > new_element->set_estimate)
			{
				tmp->set_old_ip = new_element->set_ip;
				tmp->set_estimate = new_element->set_estimate;
				tmp->set_step = new_element->set_step + 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int		to_delete(t_all *all)
{
	t_way	*tmp;

	tmp = NULL;
	if (!(all->bonus & 8) && !(all->bonus & 2))
		return (1);
	if (!(all->bonus & 8))
	{
		tmp = all->way;
		while (tmp->prev && tmp->prev->prev)
			tmp = tmp->prev;
		if (tmp->prev && tmp->hight < tmp->prev->hight)
			return (1);
	}
	return (0);
}

int		ft_find_way(t_all *all)
{
	t_arcs			*tmp;

	all->set_begining->set_estimate = 0;
	all->set_begining->set_old_ip = all->set_begining->set_ip;
	all->set_begining->set_step = 0;
	all->set_final->set_define = 1;
	if (all->set_begining->set_ip == all->set_final->set_ip)
		return (1);
	all->set_begining->set_step = 1;
	while ((tmp = ft_lawer_value(&(all->arcs))))
	{
		tmp->set_define = 1;
		if (second_parse_lower(&(all->arcs), tmp, -1))
		{
			if (!ft_way_backup(all, tmp))
				return (-1);
			else if (all->way && to_delete(all))
				return (1);
		}
	}
	if (!all->way && all->set_begining->set_ip != all->set_final->set_ip)
		return (-1);
	return (1);
}
