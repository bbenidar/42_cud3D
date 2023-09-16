/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_player_movements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:14:02 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/12 13:47:46 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_if_there_is_a_wall(t_vars *vars, int x, int y)
{
	if (vars->map[(int)((vars->player.p_y2 + y) / WALL_SIZE)]
			[(int)((vars->player.p_x2 + x) / WALL_SIZE)] == '1')
		return (1);
	return (0);
}

void	calculate_next_move_of_player(t_vars *vars)
{
	double	side_walk_flag;
	double	pixels_per_step;

	vars->player.starting_angle += vars->player.turn_direction
		* vars->player.rotation_speed;
	adjust_angles(&vars->player.starting_angle);
	if (vars->player.side_walk)
	{
		pixels_per_step = vars->player.side_walk * WALKING_SPEED
			+ (vars->speed * vars->player.side_walk);
		side_walk_flag = (M_PI / 2);
	}
	else
	{
		pixels_per_step = vars->player.walk_direction
			* WALKING_SPEED + (vars->speed * vars->player.walk_direction);
		side_walk_flag = 0;
	}
	vars->player.p_x2 = vars->player.p_x1 + cos(vars->player.starting_angle
			+ side_walk_flag) * pixels_per_step;
	vars->player.p_y2 = vars->player.p_y1 + sin(vars->player.starting_angle
			+ side_walk_flag) * pixels_per_step;
}

void	find_player_position(t_vars *v)
{
	v->j = -1;
	while (++v->j < v->height)
	{
		v->i = -1;
		while (++v->i < v->width && v->map[v->j][v->i])
		{
			if (v->map[v->j][v->i] == 'N' || v->map[v->j][v->i] == 'W'
				|| v->map[v->j][v->i] == 'S' || v->map[v->j][v->i] == 'E')
				break ;
		}
		if (v->map[v->j][v->i] == 'N' || v->map[v->j][v->i] == 'W'
			|| v->map[v->j][v->i] == 'S' || v->map[v->j][v->i] == 'E')
			break ;
	}
}

void	calculate_next_position_coordinates(t_player *player)
{
	int	hypotenuse;

	hypotenuse = (WALL_SIZE * 0.5) / 3;
	player->x_final = (MINIMAP_WIDTH / 3)
		+ (cos(player->starting_angle) * hypotenuse);
	player->y_final = (MINIMAP_HEIGHT / 3)
		+ (sin(player->starting_angle) * hypotenuse);
}

void	init_player_infos(t_vars *vars)
{
	find_player_position(vars);
	vars->speed = 0;
	vars->player.side_walk = 0;
	vars->player.turn_direction = 0;
	vars->player.walk_direction = 0;
	if (vars->map[vars->j][vars->i] == 'N')
		vars->player.starting_angle = 3 * M_PI_2;
	else if (vars->map[vars->j][vars->i] == 'W')
		vars->player.starting_angle = M_PI;
	else if (vars->map[vars->j][vars->i] == 'E')
		vars->player.starting_angle = 2 * M_PI;
	else if (vars->map[vars->j][vars->i] == 'S')
		vars->player.starting_angle = M_PI_2;
	vars->player.rotation_speed = (M_PI / 180) * 2;
	vars->player.p_x1 = vars->i * WALL_SIZE + WALL_SIZE / 2;
	vars->player.p_y1 = vars->j * WALL_SIZE + WALL_SIZE / 2;
	vars->map[vars->j][vars->i] = '0';
}
