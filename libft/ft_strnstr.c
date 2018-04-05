/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:39:43 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:40:24 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		y;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		y = 0;
		if (s2[y] == s1[i])
		{
			while (s2[y] == s1[i + y] && s2[y] && (i + y) < n)
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
