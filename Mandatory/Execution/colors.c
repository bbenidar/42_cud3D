/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:49:49 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 14:10:35 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_colors_values_from_file(t_vars *vars)
{
	t_infos	*tmp;

	tmp = vars->infos;
	while (tmp)
	{
		if (tmp->element[0] == 'C')
			vars->ceiling_color = (tmp->rgb[0] << 16)
				+ (tmp->rgb[1] << 8) + tmp->rgb[2];
		else if (tmp->element[0] == 'F')
			vars->floor_color = (tmp->rgb[0] << 16)
				+ (tmp->rgb[1] << 8) + tmp->rgb[2];
		tmp = tmp->link;
	}
}

void	get_floor_and_ceiling_color(t_vars *vars)
{
	int	ceil_grade;
	int	floor_grade;

	floor_grade = vars->floor_color;
	ceil_grade = vars->ceiling_color;
	vars->i = -1;
	while (++vars->i < WINDOW_HEIGHT / 2)
	{
		vars->j = -1;
		while (++vars->j < WINDOW_WIDTH)
			draw_pixels_on_image(&vars->image, vars->j, vars->i, ceil_grade);
	}
	vars->i--;
	while (++vars->i < WINDOW_HEIGHT)
	{
		vars->j = -1;
		while (++vars->j < WINDOW_WIDTH)
			draw_pixels_on_image(&vars->image, vars->j, vars->i, floor_grade);
		if (vars->i % 6 == 0)
			floor_grade += (1 << 16) + (1 << 8) + 1;
	}
}
