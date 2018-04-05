/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:40:36 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:40:43 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	while (len >= i)
	{
		if (s[len] == c)
			return ((char*)s + len);
		len--;
	}
	return (0);
}
