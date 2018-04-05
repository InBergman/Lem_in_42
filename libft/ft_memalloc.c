/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:13:55 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:13:58 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_memalloc(size_t size)
{
	unsigned char	*zone;
	int				i;

	i = 0;
	zone = malloc(sizeof(void) * size);
	if (!zone)
		return (NULL);
	while (size--)
		zone[i++] = '\0';
	zone[i] = '\0';
	return (zone);
}
