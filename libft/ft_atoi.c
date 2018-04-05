/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:08:21 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:08:26 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(const char *s, int i)
{
	if (s[i] == '-')
		return (1);
	else if (s[i] == '+')
		return (0);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		is_neg;

	i = 0;
	nbr = 0;
	is_neg = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || \
			str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		is_neg = ft_isneg(str, i);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += (str[i] - '0');
		i++;
	}
	is_neg ? (nbr = -nbr) : (nbr);
	return (nbr);
}
