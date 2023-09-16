/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_mous.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:46:34 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/13 16:45:23 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	mouse_event(int x, int y, t_vars *param)
{
	double	x1;

	(void)y;
	x1 = WINDOW_WIDTH / 2;
	if (param->hid_mouse == -1)
	{
		mlx_mouse_move(param->mlx_win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		x1 = x - x1;
		param->player.starting_angle += (x1 * 0.001);
	}
	return (0);
}

int	mouse_press(int bot, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (bot == 1)
		vars->fire = 1;
	return (0);
}
