/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:51:13 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:32 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

int		reboot_arc(t_all *all)
{
	t_arcs	*new_arc;

	new_arc = all->arcs;
	while (new_arc)
	{
		if (!new_arc->occupied)
		{
			new_arc->set_estimate = -1;
			new_arc->set_define = 0;
		}
		new_arc = new_arc->next;
	}
	all->set_begining->set_define = 0;
	all->set_begining->set_estimate = 0;
	return (1);
}

t_way	*add_new_way(t_all *all, t_arcs *new_element, int i)
{
	t_way	*new_way;
	t_arcs	*tmp;

	if (!(new_way = (t_way*)malloc(sizeof(*new_way))))
		return (NULL);
	new_element->occupied = 1;
	new_way->call = new_element->name_call;
	new_way->ants_number = 0;
	new_way->hight = 0;
	new_way->hight = new_element->set_estimate;
	while (new_element->set_ip != new_element->set_old_ip && ++i)
	{
		tmp = all->arcs;
		while (tmp->set_ip != new_element->set_old_ip)
			tmp = tmp->next;
		new_element = tmp;
	}
	new_way->set_step = i;
	new_way->next = NULL;
	new_way->prev = NULL;
	return (new_way);
}

void	ft_init_end_to_start(t_all *all, int i)
{
	while (all->set_begining->is_neighbour[i] != all->set_final->set_ip)
		i++;
	i -= 1;
	while (++i + 1 < all->set_begining->set_way)
		all->set_begining->is_neighbour[i] = \
	all->set_begining->is_neighbour[i + 1];
	all->set_begining->is_neighbour[i] = 0;
	all->set_begining->set_way -= 1;
}

t_way	*ft_put_last_way(t_all *all, t_arcs *new_element, int i)
{
	t_way	*new_way;
	t_arcs	*tmp1;
	t_arcs	*tmp2;

	if (!(new_way = (t_way*)malloc(sizeof(*new_way))))
		return (NULL);
	all->set_final->set_final = 1;
	new_way->call = all->set_final->name_call;
	new_way->ants_number = 0;
	new_way->hight = 0;
	new_way->hight = new_element->set_estimate;
	tmp1 = new_element;
	while (tmp1->set_ip != tmp1->set_old_ip && ++i)
	{
		tmp2 = all->arcs;
		while (tmp2->set_ip != tmp1->set_old_ip)
			tmp2 = tmp2->next;
		tmp1 = tmp2;
	}
	new_way->set_step = i;
	new_way->next = NULL;
	new_way->prev = NULL;
	return (new_way);
}

int		ft_way_backup(t_all *all, t_arcs *browse)
{
	t_way	*my_way;
	t_arcs	*my_arc;

	all->select_number += 1;
	my_way = all->way;
	while (my_way && my_way->prev)
		my_way = my_way->prev;
	(my_way) ? my_way->prev = ft_put_last_way(all, browse, 1) : 0;
	(!my_way) ? all->way = ft_put_last_way(all, browse, 1) : 0;
	if (!all->way || (my_way && !my_way->prev))
		return (0);
	my_way = (!my_way) ? all->way : my_way->prev;
	if (browse->set_ip == all->set_begining->set_ip)
		ft_init_end_to_start(all, 0);
	while (browse->set_old_ip != browse->set_ip)
	{
		if (!(my_way->next = add_new_way(all, browse, 1)))
			return (0);
		my_way = my_way->next;
		my_arc = all->arcs;
		while (my_arc->set_ip != browse->set_old_ip)
			my_arc = my_arc->next;
		browse = my_arc;
	}
	return (reboot_arc(all));
}
