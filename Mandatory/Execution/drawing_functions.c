/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 19:12:39 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_pixels_on_image(t_img *img, int x, int y, int color)
{
	int		position;
	char	*pixel;

	if (x < 0 || y < 0 || y >= WINDOW_HEIGHT || x >= WINDOW_WIDTH)
		return ;
	position = ((x * (img->bits_per_pixel / 8)) + (y * img->line_length));
	pixel = img->addr + position;
	*(int *)pixel = color;
}

int	render_game(t_vars *vars)
{
	calculate_next_move_of_player(vars);
	get_floor_and_ceiling_color(vars);
	if (wall_collision(vars) == 0)
	{
		vars->player.p_x1 = vars->player.p_x2;
		vars->player.p_y1 = vars->player.p_y2;
	}
	initialize_rays_infos(vars);
	calculate_ending_point_coordinates_of_player_line(&vars->player);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->image.img, 0, 0);
	mlx_string_put(vars->mlx, vars->mlx_win, 450, 700, 0x111,
		"+: increase player speed   -: decrease player speed");
	return (0);
}
