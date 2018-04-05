/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 23:06:37 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:00 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

int		manage_ants_sent(t_all *all, int actions)
{
	t_way	*fist_way;
	t_way	*second_way;
	int		i;

	i = 0;
	second_way = all->way;
	fist_way = (all->way) ? all->way->prev : NULL;
	if (second_way && !(i = 0) && all->let_shoot + i < all->ants_number && ++i)
	{
		all->division_set += second_way->hight;
		while (second_way->next)
			second_way = second_way->next;
		second_way->ants_number = all->let_shoot + i;
		print_algo(second_way->ants_number, second_way->call, i + actions);
	}
	return (i);
}

int		manage_ant(t_all *all, int i)
{
	t_way	*ant_path;

	ant_path = all->way;
	while (ant_path)
	{
		ant_path->ants_number = (ant_path->next && \
		ant_path->next->ants_number) ? \
		ant_path->next->ants_number : 0;
		(ant_path->ants_number && ant_path->next && ++i) ? \
		print_algo(ant_path->ants_number, ant_path->call, i) : 0;
		ant_path = ant_path->next;
	}
	return (i);
}

void	ft_dijkstra(t_all *all, int i)
{
	int		moves;
	int		sent;

	print_init(&(all->links));
	while (i && all->arcs)
	{
		i = 0;
		moves = 0;
		sent = 0;
		moves += manage_ant(all, 0);
		sent += manage_ants_sent(all, moves);
		all->let_shoot += sent;
		i = moves + sent;
		all->actions += i;
		all->turn += (i) ? 1 : 0;
		(i) ? ft_putchar('\n') : 0;
	}
}
