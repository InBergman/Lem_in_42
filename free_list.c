/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 22:23:41 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:04:58 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

void	free_links(t_links **start)
{
	t_links	*tmp1;
	t_links	*tmp2;

	tmp1 = *start;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		if (tmp2->call)
			free(tmp2->call);
		tmp2->next = NULL;
		free(tmp2);
		tmp2 = NULL;
	}
}

void	free_arcs(t_arcs **start)
{
	t_arcs	*tmp1;
	t_arcs	*tmp2;

	tmp1 = *start;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2->name_call);
		while (tmp2->set_way > 0)
		{
			tmp2->set_way -= 1;
			tmp2->is_neighbour[tmp2->set_way] = 0;
		}
		free(tmp2->is_neighbour);
		tmp2->is_neighbour = NULL;
		free(tmp2);
	}
}

void	free_way(t_way **start)
{
	t_way	*tmp1;
	t_way	*tmp2;
	t_way	*tmp3;

	tmp1 = *start;
	while (tmp1 && tmp1->prev)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->prev;
		while (tmp2)
		{
			tmp3 = tmp2;
			tmp2 = tmp2->next;
			free(tmp3);
			tmp3 = NULL;
		}
	}
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
		tmp2 = NULL;
	}
}

int		free_all(t_all *all)
{
	free_links(&(all->links));
	all->links = NULL;
	free_arcs(&(all->arcs));
	all->arcs = NULL;
	free_way(&(all->way));
	all->way = NULL;
	all->set_begining = NULL;
	all->set_final = NULL;
	return (1);
}
