/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:57:15 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:04:54 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

int			main(void)
{
	t_all	basic;

	init_var(&basic);
	if (check_start(&basic) < 0)
		ft_putendl_fd("ERROR", 2);
	else if (ft_find_way(&basic) < 0)
		ft_putendl_fd("ERROR", 2);
	else
		ft_dijkstra(&basic, 1);
	free_all(&basic);
	return (0);
}
