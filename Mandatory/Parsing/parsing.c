/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:31:19 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 19:20:40 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_data(t_infos **infos, char **elements, char **arr)
{
	if (arr)
		ft_free_arr(arr);
	if (infos)
		ft_destroy_list(infos);
	if (elements)
		ft_free_arr(elements);
}

void	first_checks(int ac)
{
	if (ac < 2)
		ft_error(1, 0, 0, 0);
	else if (ac > 2)
		ft_error(2, 0, 0, 0);
	if (WINDOW_HEIGHT != 720 || WINDOW_WIDTH != 1280)
		ft_error(8, 0, 0, 0);
	if (WALKING_SPEED < 0 || WALKING_SPEED > 10)
		ft_error(9, 0, 0, 0);
}

void	ft_error(int cases, t_infos **infos, char **elements, char **arr)
{
	if (cases == 1)
		ft_putstr("\e[1m\x1B[31mError: \e[37mToo few arguments.\n");
	else if (cases == 2)
		ft_putstr("\e[1m\x1B[31mError: \e[37mToo many arguments.\n");
	else if (cases == 3)
		ft_putstr("\e[1m\x1B[31mError: \e[37mInvalid extension.\n");
	else if (cases == 4)
		ft_putstr("\e[1m\x1B[31mError: \e[37mFile does not exist.\n");
	else if (cases == 5)
		ft_putstr("\e[1m\x1B[31mError: \e[37mElements are invalid.\n");
	else if (cases == 6)
		ft_putstr("\e[1m\x1B[31mError: \e[37mMap's not sealed! Edit and retry.\n");
	else if (cases == 7)
		ft_putstr("\e[1m\x1B[31mError: \e[37mElements are invalid.\n");
	else if (cases == 8)
		ft_putstr("\e[1m\x1B[31mError: \e[37mResolution not supported.\n");
	else if (cases == 9)
		ft_putstr("\e[1m\x1B[31mError: \e[37mAdjust player settings.\n");
	else if (cases == 10)
	{
		ft_putstr("\e[1m\x1B[31mError: \e[37mSomething wrong ");
		ft_putstr("with the files.\n");
	}
	free_data(infos, elements, arr);
	exit(1);
}

int	check_valid_extension(char *file_name)
{
	int	start_of_extension;

	if (ft_strcmp(file_name, ".cub") == 0)
		return (1);
	else
	{
		start_of_extension = ft_strlen(file_name) - 4;
		if (ft_strcmp(file_name + start_of_extension, ".cub") == 0)
			return (0);
	}
	return (1);
}
