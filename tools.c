/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:32:45 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:04:04 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

void		init_var(t_all *basic)
{
	basic->arcs = NULL;
	basic->way = NULL;
	basic->links = NULL;
	basic->ants_number = 0;
	basic->select_number = 0;
	basic->set_begining = NULL;
	basic->set_final = NULL;
	basic->bonus = 0;
	basic->let_shoot = 0;
	basic->turn = 0;
	basic->actions = 0;
	basic->division_set = 0;
}

int			is_space(char *str, int i)
{
	while (str[i] && str[i] != ' ')
		i++;
	return ((str[i] == ' ') ? 1 : 0);
}

void		set_empty(char **str)
{
	if (str && *str)
		ft_memdel((void**)str);
}

int			do_touch(char *str, int i)
{
	while (str[++i])
		if (str[i] == '-')
			break ;
	if ((str[i] && i == 0) || (str[i] && str[i - 1] != ' '))
		return (1);
	return (0);
}
