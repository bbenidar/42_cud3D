/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:46:38 by bbenidar          #+#    #+#             */
/*   Updated: 2023/08/31 12:33:51 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_count_elem(char **str)
{
	int			i;
	int			j;
	static int	count;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S'
				|| str[i][j] == 'E' || str[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1 || count == 0)
		return (0);
	return (1);
}

int	ft_check_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ' && str[i][j] != '1' && str[i][j] != '0'
				&& str[i][j] != 'N' && str[i][j] != 'S'
				&& str[i][j] != 'E' && str[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_empty(char *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'S' || map[i] == '0'
			|| map[i] == 'E' || map[i] == 'W' || map[i] == '1')
			c++;
		i++;
	}
	if (c == 0)
		return (0);
	return (1);
}

int	check_for_empty_line(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_empty(str[i]) == 0)
		{
			while (is_empty(str[i]) == 0)
				i++;
			if (str[i] != NULL)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int	general_map_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (check_for_empty_line(map))
		return (ft_error(7, 0, 0, 0), 0);
	if (!ft_count_elem(map) || !ft_check_map(map))
		return (ft_error(7, 0, 0, 0), 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == '0'
				|| map[i][j] == 'E' || map[i][j] == 'W' )
					&& !check_wall(map, i, j))
				return (ft_error(6, 0, 0, 0), 0);
			j++;
		}
		i++;
	}
	return (1);
}
