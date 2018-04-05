/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:10:47 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:10:52 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_intlen(int n)
{
	int			i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char		*ft_intmax(void)
{
	char		*str;

	str = ft_strnew(11);
	if (!str)
		return (NULL);
	ft_strcpy(str, "-2147483648");
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			is_neg;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_intmax());
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	str[--len] = (n % 10) + 48;
	if (is_neg)
		str[--len] = '-';
	return (str);
}
