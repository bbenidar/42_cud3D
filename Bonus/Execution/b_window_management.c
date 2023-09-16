/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_window_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:19:21 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 13:00:31 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free_data(&vars->infos, NULL, vars->map);
	free (vars->lengths);
	free (vars);
	exit(0);
}

void	create_new_image(t_vars *vars)
{
	vars->image.win_img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!vars->image.win_img)
		exit (1);
	vars->image.win_addr = mlx_get_data_addr(vars->image.win_img,
			&vars->image.bits_per_pixel, &vars->image.line_length,
			&vars->image.endian);
	if (!vars->image.win_addr)
		exit (1);
}

void	create_minimap_image(t_vars *vars)
{
	vars->minimap.minimap_img
		= mlx_new_image(vars->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	vars->minimap.minimap_addr = mlx_get_data_addr(vars->minimap.minimap_img,
			&vars->minimap.bits_per_pixel, &vars->minimap.line_length,
			&vars->minimap.endian);
}

void	open_window(t_vars *vars)
{
	vars->amo = 30;
	vars->ammo_full = 300;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(1);
	get_window_resolution(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Cub3D");
	if (!vars->mlx_win)
		exit(1);
	if (vars->hid_mouse == -1)
		mlx_mouse_move(vars->mlx_win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	ft_texture(vars);
	ft_get_gun_img(vars);
	create_new_image(vars);
	create_minimap_image(vars);
	init_player_infos(vars);
	get_colors_values_from_file(vars);
}
