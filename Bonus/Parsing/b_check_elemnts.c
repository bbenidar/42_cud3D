/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_check_elemnts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:49:46 by bbenidar          #+#    #+#             */
/*   Updated: 2023/08/31 12:33:55 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_tablen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_wall(char **str, int i, int j)
{
	if (j == 0)
		return (0);
	if (i == 0)
		return (0);
	else if (i == ft_tablen(str) - 1)
		return (0);
	else if (str[i][j + 1] == ' ' || str[i][j - 1] == ' '
		|| str[i + 1][j] == ' ' || str[i - 1][j] == ' ')
		return (0);
	else if (str[i][j + 1] == '\0' || str[i][j - 1] == '\0'
		|| str[i + 1][j] == '\0' || str[i - 1][j] == '\0')
		return (0);
	return (1);
}
