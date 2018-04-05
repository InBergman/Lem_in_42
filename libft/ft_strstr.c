/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:42:57 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:43:00 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		y;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		y = 0;
		if (s2[y] == s1[i])
		{
			while (s2[y] == s1[i + y] && s2[y])
			{
				if (s2[y + 1] == '\0')
				{
					return ((char*)s1 + i);
				}
				y++;
			}
		}
		i++;
	}
	return (NULL);
}
