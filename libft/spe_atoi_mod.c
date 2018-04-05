/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_atoi_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 17:04:14 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:02:34 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			spe_atoi_mod(char *s, int *number)
{
	int		my_tmp_number;
	int		i;

	my_tmp_number = 0;
	i = (s[0] == '+' && ft_isdigit(s[1])) ? 1 : 0;
	while (i >= 0 && s[i])
	{
		if (my_tmp_number == 214748364 && s[i] > '7')
			i = -2;
		else if (s[i] < '0' || s[i] > '9' || my_tmp_number > 214748364)
			i = -2;
		else
		{
			my_tmp_number = my_tmp_number * 10 + s[i] - 48;
			i++;
		}
	}
	*number = my_tmp_number;
	return (i);
}
