/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_draw_pixels_on_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:14:11 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/13 19:08:01 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_pixels_on_minimap_image(t_minimap *minimap, int x, int y,
	int color)
{
	int		position;
	char	*pixel;

	if (x < 0 || y < 0 || y >= MINIMAP_HEIGHT || x >= MINIMAP_WIDTH)
		return ;
	position = ((x * (minimap->bits_per_pixel / 8))
			+ (y * minimap->line_length));
	pixel = minimap->minimap_addr + position;
	*(int *)pixel = color;
}

/**
 * draw_line - This function draws a line between two points defined by
 *  'vars->x1', 'vars->y1' (starting point) and 'x2', 'y2' (ending point)
 *  with the specified 'color' on the image.
 * @vars: A pointer to a struct containing image data and line coordinates.
 * @x2: The x-coordinate of the ending point of the line.
 * @y2: The y-coordinate of the ending point of the line.
 * @color: An integer representing the color of the line to be drawn.
*/
void	draw_line(t_vars *vars, double x2, double y2, int color)
{
	double	dx;
	double	dy;
	int		steps;
	double	x_inc;
	double	y_inc;

	vars->x1 = MINIMAP_WIDTH / 3;
	vars->y1 = MINIMAP_HEIGHT / 3;
	dx = x2 - vars->x1;
	dy = y2 - vars->y1;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x2 = 0;
	while (x2++ < steps)
	{
		draw_pixels_on_minimap_image(&vars->minimap,
			(int)round(vars->x1), (int)round(vars->y1), color);
		vars->x1 = vars->x1 + x_inc;
		vars->y1 = vars->y1 + y_inc;
	}
}

void	draw_circle(int x, int y, t_minimap *minimap)
{
	int		a;
	int		x1;
	int		y1;
	double	x2;
	double	y2;

	a = 0;
	x1 = x;
	y1 = y;
	while (a < 360)
	{
		x2 = x1 + cos(a * M_PI / 180) * 4;
		y2 = y1 + sin(a * M_PI / 180) * 4;
		draw_pixels_on_minimap_image(minimap, x2, y2, 0xB85042);
		a++;
	}
}

void	draw_pixels_on_image(t_img *img, int x, int y, int color)
{
	int		position;
	char	*pixel;

	if (x < 0 || y < 0 || y >= WINDOW_HEIGHT || x >= WINDOW_WIDTH)
		return ;
	position = ((x * (img->bits_per_pixel / 8)) + (y * img->line_length));
	pixel = img->win_addr + position;
	*(int *)pixel = color;
}

void	draw_pixel_on_map(t_vars *vars, double start_x, double start_y)
{
	if (start_x >= 0
		&& start_y >= 0 && start_x / WALL_SIZE >= 0
		&& start_y / WALL_SIZE >= 0
		&& start_y < vars->height * WALL_SIZE
		&& start_x
		< (int)ft_strlen(vars->map[(int)(start_y / WALL_SIZE)]) * WALL_SIZE)
	{
		if (vars->map[(int)(start_y / WALL_SIZE)][(int)(start_x
					/ WALL_SIZE)] == '1')
			draw_pixels_on_minimap_image(&vars->minimap,
				(int)(vars->i / 3), (int)(vars->j / 3), 0x000000);
		else if (vars->map[(int)(start_y / WALL_SIZE)][(int)(start_x
					/ WALL_SIZE)] == '0')
			draw_pixels_on_minimap_image(&vars->minimap,
				(int)(vars->i / 3), (int)(vars->j / 3), 0xa4978e);
	}
}
