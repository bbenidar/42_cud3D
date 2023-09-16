/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:07:05 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/10 15:16:05 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 1)
		vars->player.walk_direction = FALSE;
	else if (keycode == 0 || keycode == 2)
		vars->player.side_walk = FALSE;
	else if (keycode == 123 || keycode == 124)
		vars->player.turn_direction = FALSE;
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 124)
		vars->player.turn_direction = RIGHT;
	else if (keycode == 123)
		vars->player.turn_direction = LEFT;
	else if (keycode == 13)
		vars->player.walk_direction = FORWARD;
	else if (keycode == 1)
		vars->player.walk_direction = BACKWARD;
	else if (keycode == 0)
		vars->player.side_walk = LEFT;
	else if (keycode == 2)
		vars->player.side_walk = RIGHT;
	else if (keycode == 69)
	{
		if (vars->speed < 7)
			vars->speed++;
	}
	else if (keycode == 78)
	{
		if (vars->speed > 1)
			vars->speed--;
	}
	return (0);
}
