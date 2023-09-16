/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:19:21 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/14 16:57:56 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_window_resolution(t_vars *vars)
{
	int	i;

	i = -1;
	vars->width = 0;
	vars->height = 0;
	while (vars->map[vars->height])
	{
		if ((int)ft_strlen(vars->map[vars->height]) > vars->width)
			vars->width = ft_strlen(vars->map[vars->height]);
		vars->height++;
	}
	vars->lengths = malloc ((vars->height + 1) * sizeof(int));
	if (!vars->lengths)
		exit(1);
	while (++i < vars->height)
		vars->lengths[i] = (int)ft_strlen(vars->map[i]);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image.img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free_data(&vars->infos, NULL, vars->map);
	free (vars->lengths);
	free (vars);
	exit(0);
}

void	create_new_image(t_vars *vars)
{
	vars->image.img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!vars->image.img)
		exit (1);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel, &vars->image.line_length,
			&vars->image.endian);
	if (!vars->image.addr)
		exit (1);
}

void	open_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(1);
	ft_texture(vars);
	get_window_resolution(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Cub3D");
	if (!vars->mlx_win)
		exit(1);
	create_new_image(vars);
	init_player_infos(vars);
	get_colors_values_from_file(vars);
}
