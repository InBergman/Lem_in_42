/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:32:12 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:32:16 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;
	unsigned int		len;

	i = 0;
	len = 0;
	if (s && (*f))
	{
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(i++, s++);
		}
	}
}
