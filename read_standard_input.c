/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberedda <mberedda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 18:26:42 by Macintosh         #+#    #+#             */
/*   Updated: 2016/11/03 15:04:07 by mberedda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/lem_in.h"

char	*join_free(char *argv, char str)
{
	int		i;
	char	*new_tmp;

	i = (argv) ? ft_strlen(argv) + 1 : 1;
	if (!(new_tmp = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (argv && argv[i])
	{
		new_tmp[i] = argv[i];
		i++;
	}
	new_tmp[i] = str;
	new_tmp[i + 1] = '\0';
	if (argv)
		free(argv);
	return (new_tmp);
}

int		read_standard_input(char **argv)
{
	int		i;
	int		ret;
	char	buff[1];
	char	*value_tmp;

	i = 0;
	value_tmp = NULL;
	while ((ret = read(0, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			break ;
		if (!(value_tmp = join_free(value_tmp, buff[0])))
			return (-1);
	}
	*argv = value_tmp;
	if (ret < 0)
		return (ret);
	return ((!value_tmp || !(*value_tmp)) ? 0 : 1);
}
