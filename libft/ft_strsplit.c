/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:40:55 by mberedda          #+#    #+#             */
/*   Updated: 2015/12/04 17:41:53 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_blank(char const *s, int i, char c)
{
	if (s[i] == c && s[i])
	{
		while (s[i] == c && s[i])
			i++;
	}
	return (i);
}

static int			ft_word(char const *s, char c)
{
	int				i;
	int				word;

	i = 0;
	word = 0;
	while (s[i])
	{
		i = ft_blank(s, i, c);
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

static int			ft_strlenword(char const *s, int i, char c)
{
	int				len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	int				word;
	char			**tab;
	int				len;
	int				i;

	i = 0;
	if (!s || !c)
		return (NULL);
	tab = malloc((ft_word(s, c) + 1) * sizeof(char*));
	if (!tab)
		return (NULL);
	word = 0;
	while (s[i])
	{
		i = ft_blank(s, i, c);
		if (s[i] != c && s[i])
		{
			len = ft_strlenword(s, i, c);
			i += len;
			tab[word++] = ft_strsub(s, i - len, len);
		}
	}
	tab[word] = 0;
	return (tab);
}
