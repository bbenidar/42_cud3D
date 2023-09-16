/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_wall_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:10:54 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/14 17:00:13 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	correct_intersection_values(t_vars *vars,
	double *ray_x, double *ray_y, int flag)
{
	double	number;

	number = 0.001;
	if (flag == 1)
		number *= -1;
	if (vars->ray[vars->i].up_down == UP)
		*ray_y += number;
	if (vars->ray[vars->i].left_right == LEFT)
		*ray_x += number;
}

int	wall_collision(t_vars *vars)
{
	if (check_if_there_is_a_wall(vars, 0, -12))
		return (1);
	else if (check_if_there_is_a_wall(vars, 0, 12))
		return (1);
	else if (check_if_there_is_a_wall(vars, -12, 0))
		return (1);
	else if (check_if_there_is_a_wall(vars, 12, 0))
		return (1);
	else if (check_if_there_is_a_wall(vars, -12, -12))
		return (1);
	else if (check_if_there_is_a_wall(vars, 12, -12))
		return (1);
	else if (check_if_there_is_a_wall(vars, -12, 12))
		return (1);
	else if (check_if_there_is_a_wall(vars, 12, 12))
		return (1);
	return (0);
}

void	find_first_intersection_with_wall(t_vars *vars,
	double *ray_x, double *ray_y)
{
	while (*ray_x >= 0 && *ray_y >= 0 && *ray_y < vars->height * WALL_SIZE
		&& *ray_x < vars->lengths[(int)(*ray_y / WALL_SIZE)] * WALL_SIZE)
	{
		correct_intersection_values(vars, ray_x, ray_y, 1);
		if (*ray_x < (int)ft_strlen(vars->map[(int)(*ray_y / WALL_SIZE)])
			* WALL_SIZE && vars->map[(int)(*ray_y / WALL_SIZE)]
				[(int)(*ray_x / WALL_SIZE)] != '0')
		{
			correct_intersection_values(vars, ray_x, ray_y, 0);
			break ;
		}
		else
		{
			correct_intersection_values(vars, ray_x, ray_y, 0);
			*ray_x += vars->xstep;
			*ray_y += vars->ystep;
		}
	}
}

/*
 * a_x and vars->a_y are the coordinates of
 * the first horizontal intersection point
*/
void	horizontal_wall_intersection(t_vars *vars)
{
	what_direction_the_player_is_facing(vars);
	vars->a_y = (int)(vars->player.p_y1 / WALL_SIZE) * WALL_SIZE;
	if (vars->ray[vars->i].up_down == DOWN)
		vars->a_y += WALL_SIZE;
	vars->a_x = vars->player.p_x1
		+ (vars->a_y - vars->player.p_y1) / tan(vars->ray[vars->i].ray_angle);
	vars->ystep = WALL_SIZE;
	if (vars->ray[vars->i].up_down == UP)
		vars->ystep *= -1;
	vars->xstep = vars->ystep / tan(vars->ray[vars->i].ray_angle);
	vars->ray[vars->i].horizontal_intersection_x = vars->a_x;
	vars->ray[vars->i].horizontal_intersection_y = vars->a_y;
	find_first_intersection_with_wall(vars,
		&vars->ray[vars->i].horizontal_intersection_x,
		&vars->ray[vars->i].horizontal_intersection_y);
}

void	vertical_wall_intersection(t_vars *vars)
{
	what_direction_the_player_is_facing(vars);
	vars->a_x = (int)(vars->player.p_x1 / WALL_SIZE) * WALL_SIZE;
	if (vars->ray[vars->i].left_right == RIGHT)
		vars->a_x += WALL_SIZE;
	vars->a_y = vars->player.p_y1 + ((vars->a_x - vars->player.p_x1)
			* tan(vars->ray[vars->i].ray_angle));
	vars->xstep = WALL_SIZE;
	if (vars->ray[vars->i].left_right == LEFT)
		vars->xstep *= -1;
	vars->ystep = vars->xstep * tan(vars->ray[vars->i].ray_angle);
	vars->ray[vars->i].vertical_intersection_x = vars->a_x;
	vars->ray[vars->i].vertical_intersection_y = vars->a_y;
	find_first_intersection_with_wall(vars,
		&vars->ray[vars->i].vertical_intersection_x,
		&vars->ray[vars->i].vertical_intersection_y);
}
