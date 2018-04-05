/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 22:13:31 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:04:10 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

void		print_init(t_links **starter)
{
	t_links	*tmp;

	tmp = *starter;
	while (tmp)
	{
		ft_putendl(tmp->call);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		print_algo(int ant, char *name, int moved)
{
	(moved > 1) ? ft_putstr(" L") : ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
}
