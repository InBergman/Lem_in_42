/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:43:23 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:43:27 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strtrim(char const *s)
{
	char			*str;
	int				len;
	int				start;
	int				i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (len == -1)
		len = 0;
	else
		len = len - start + 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
