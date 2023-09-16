/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:24:53 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/14 15:17:52 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	get_pixel_color(t_vars *vars,
			int offsetx, double projected_wall_height, int flag)
{
	double			offset_y;

	if (flag == 1)
		offset_y = (vars->line_y1 - vars->top)
			* ((float)vars->xpm_height / projected_wall_height);
	if (flag == 2)
		offset_y = (vars->line_y1 - vars->top)
			* ((float)vars->xpm_height2 / projected_wall_height);
	if (flag == 3)
		offset_y = (vars->line_y1 - vars->top)
			* ((float)vars->xpm_height3 / projected_wall_height);
	if (flag == 4)
		offset_y = (vars->line_y1 - vars->top)
			* ((float)vars->xpm_height4 / projected_wall_height);
	return (draw_pixels_image(&vars->image, offsetx, offset_y, flag));
}

void	color_set(t_vars *vars, unsigned int *color, int offsetx)
{
	if (vars->ray[vars->i].up_down == UP
		&& !vars->ray[vars->i].was_hit_v)
		*color = get_pixel_color(vars, offsetx, vars->projected_wall_height, 1);
	else if (vars->ray[vars->i].up_down == DOWN
		&& !vars->ray[vars->i].was_hit_v)
		*color = get_pixel_color(vars, offsetx, vars->projected_wall_height, 3);
	else if (vars->ray[vars->i].left_right == LEFT
		&& vars->ray[vars->i].was_hit_v)
		*color = get_pixel_color(vars, offsetx, vars->projected_wall_height, 2);
	else if (vars->ray[vars->i].left_right == RIGHT
		&& vars->ray[vars->i].was_hit_v)
		*color = get_pixel_color(vars, offsetx, vars->projected_wall_height, 4);
}

void	draw_wall_column(t_vars *vars, unsigned int *color)
{
	while (vars->line_y1 < vars->line_y2)
	{
		color_set(vars, color, vars->offsetx);
		draw_pixels_on_image(&vars->image, vars->i, vars->line_y1, *color);
		vars->line_y1++;
	}
}

void	rendering_walls(t_vars *vars)
{
	unsigned int	color;

	vars->i = -1;
	while (++vars->i < WINDOW_WIDTH)
	{
		vars->correct_wall_height = vars->ray[vars->i].distance
			* cos(vars->ray[vars->i].ray_angle - vars->player.starting_angle);
		vars->projected_wall_height = (WALL_SIZE / vars->correct_wall_height)
			* ((WINDOW_WIDTH / 2) / tan(vars->fov_angle / 2));
		vars->line_y1 = (WINDOW_HEIGHT / 2) - (vars->projected_wall_height / 2);
		vars->line_y2 = vars->line_y1 + vars->projected_wall_height;
		vars->top = vars->line_y1;
		if (vars->ray[vars->i].was_hit_v == 1)
			vars->offsetx = fmod(vars->ray[vars->i].wallhit_y
					* vars->xpm_width / 64, vars->xpm_width);
		else
			vars->offsetx = fmod(vars->ray[vars->i].wallhit_x
					* vars->xpm_width2 / 64, vars->xpm_width2);
		if (vars->line_y1 < 0)
			vars->line_y1 = 0;
		draw_wall_column(vars, &color);
	}
}
