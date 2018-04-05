/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_associability.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:36:49 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:05:27 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

t_arcs	*looking_for_arc(t_arcs **start, char *s, int i, int choice)
{
	t_arcs	*t;
	int		j;

	t = *start;
	if (choice == 1)
		while (t)
		{
			j = 0;
			while (s[j] && t->name_call[j] && s[j] == t->name_call[j])
				j++;
			if (j == i && t->name_call[j] == '\0')
				break ;
			t = t->next;
		}
	else
		while (t)
		{
			j = 0;
			while (s[i + j] && t->name_call[j] && s[i + j] == t->name_call[j])
				j++;
			if (s[i + j] == '\0' && t->name_call[j] == '\0')
				break ;
			t = t->next;
		}
	return (t);
}

int		plus_neighbour(t_arcs *arcs, int ip)
{
	int		*tab;
	int		i;

	tab = arcs->is_neighbour;
	arcs->set_way += 1;
	if (!(arcs->is_neighbour = (int*)malloc(sizeof(int) * (arcs->set_way))))
		return (0);
	i = -1;
	while (++i + 1 < arcs->set_way)
		arcs->is_neighbour[i] = tab[i];
	arcs->is_neighbour[i] = ip;
	if (tab)
		free(tab);
	return (1);
}

int		check_neighboor(t_arcs **start, char *str, int i)
{
	t_arcs	*tmp1;
	t_arcs	*tmp2;

	tmp1 = looking_for_arc(start, str, i, 1);
	i++;
	tmp2 = looking_for_arc(start, str, i, 2);
	if (!tmp1 || !tmp2 || ft_strequ(tmp1->name_call, tmp2->name_call))
		return (0);
	if (!plus_neighbour(tmp1, tmp2->set_ip) \
		|| !plus_neighbour(tmp2, tmp1->set_ip))
		return (-1);
	return (1);
}

int		get_neighbour(t_all *all, char **str, int i)
{
	while (*str)
	{
		if (str[0][0] == '#')
		{
			if (ft_strequ("##start", *str) || ft_strequ("##end", *str))
				return (-1);
		}
		else if (str[0][0] == 'L' || !ft_strchr(*str, '-'))
			return (0);
		else if ((i = ft_strchr(*str, '-') - *str) <= 0)
			return (0);
		else if ((i = check_neighboor(&(all->arcs), *str, i)) <= 0)
			return (i);
		if (!set_sommet(&(all->links), str))
			return (-2);
		if (read_standard_input(str) < 0)
			return (-1);
	}
	return (i);
}
