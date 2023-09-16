/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:57:31 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 17:26:14 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	adjust_angles(double *ray_angle)
{
	*ray_angle = fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle += (2 * M_PI);
}

void	what_direction_the_player_is_facing(t_vars *vars)
{
	if (vars->ray[vars->i].ray_angle < M_PI)
		vars->ray[vars->i].up_down = DOWN;
	if (vars->ray[vars->i].ray_angle < M_PI_2
		|| vars->ray[vars->i].ray_angle > (3 * M_PI_2))
		vars->ray[vars->i].left_right = RIGHT;
}

void	get_ray_distance(t_vars *vars)
{
	vars->vertical_distance = fabs(vars->player.p_x1
			- vars->ray[vars->i].vertical_intersection_x)
		/ fabs(cos(vars->ray[vars->i].ray_angle));
	vars->horizontal_distance = fabs(vars->player.p_x1
			- vars->ray[vars->i].horizontal_intersection_x)
		/ fabs(cos(vars->ray[vars->i].ray_angle));
	if (vars->horizontal_distance < vars->vertical_distance)
	{
		vars->ray[vars->i].wallhit_x
			= vars->ray[vars->i].horizontal_intersection_x;
		vars->ray[vars->i].wallhit_y
			= vars->ray[vars->i].horizontal_intersection_y;
		vars->ray[vars->i].distance = vars->horizontal_distance;
		vars->ray[vars->i].was_hit_v = 0;
	}
	else
	{
		vars->ray[vars->i].wallhit_x
			= vars->ray[vars->i].vertical_intersection_x;
		vars->ray[vars->i].wallhit_y
			= vars->ray[vars->i].vertical_intersection_y;
		vars->ray[vars->i].distance = vars->vertical_distance;
		vars->ray[vars->i].was_hit_v = 1;
	}
}

void	initialize_rays_infos(t_vars *vars)
{
	double	ray_angle;

	vars->i = -1;
	vars->fov_angle = 60 * (M_PI / 180);
	ray_angle = vars->player.starting_angle - (vars->fov_angle / 2);
	while (++vars->i < WINDOW_WIDTH)
	{
		adjust_angles(&ray_angle);
		vars->ray[vars->i].up_down = UP;
		vars->ray[vars->i].left_right = LEFT;
		vars->ray[vars->i].ray_angle = ray_angle;
		vertical_wall_intersection(vars);
		horizontal_wall_intersection(vars);
		get_ray_distance(vars);
		ray_angle += vars->fov_angle / WINDOW_WIDTH;
	}
	rendering_walls(vars);
}
