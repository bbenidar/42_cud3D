/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:36:14 by moudrib           #+#    #+#             */
/*   Updated: 2023/08/02 09:36:21 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	while (str[i])
		if (!(str[i] >= '0' && str[i++] <= '9'))
			return (1);
	return (0);
}

int	is_printable(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32)
			return (1);
		i++;
	}
	return (0);
}

int	count_commas(char *value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (value[i])
	{
		if (value[i] == ',')
			count++;
		i++;
	}
	return (count);
}
