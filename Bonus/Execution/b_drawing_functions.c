/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_drawing_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:06:11 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/13 19:12:39 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	minimap(t_vars *vars)
{
	double	start_x;
	double	start_y;

	vars->j = -1;
	start_y = vars->player.p_y1 - MINIMAP_HEIGHT;
	while (++vars->j < MINIMAP_HEIGHT * 3)
	{
		vars->i = -1;
		start_x = vars->player.p_x1 - MINIMAP_WIDTH;
		while (++vars->i < MINIMAP_WIDTH * 3)
		{
			draw_pixel_on_map(vars, start_x, start_y);
			start_x++;
		}
		start_y++;
	}
}

void	ft_get_amo(t_vars *vars)
{
	char	*str;
	char	*tmp;

	if (vars->weapon == 1)
	{
		tmp = ft_itoa(vars->amo);
		str = ft_strjoin(ft_strdup("ammo : "), tmp);
		free(tmp);
		str = ft_strjoin(str, "/");
		tmp = ft_itoa(vars->ammo_full);
		str = ft_strjoin(str, tmp);
		free(tmp);
		mlx_string_put(vars->mlx, vars->mlx_win, 550, 100, 0xFFFFFF, str);
		free(str);
	}
	mlx_string_put(vars->mlx, vars->mlx_win, 450, 700, 0x111,
		"+: increase player speed   -: decrease player speed");
}

void	render_game_splt(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->image.win_img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win,
		vars->minimap.minimap_img, 0, 0);
	if (vars->weapon == 0)
		player_animation(vars);
	else
		player_pistl_animation(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->rec, 250, 0);
	if (vars->rec)
	{
		mlx_destroy_image(vars->mlx, vars->rec);
		vars->rec = NULL;
	}
	ft_get_amo(vars);
}

int	render_game(t_vars *vars)
{
	vars->y = -1;
	calculate_next_move_of_player(vars);
	get_floor_and_ceiling_color(vars);
	if (wall_collision(vars) == 0)
	{
		vars->player.p_x1 = vars->player.p_x2;
		vars->player.p_y1 = vars->player.p_y2;
	}
	initialize_rays_infos(vars);
	calculate_next_position_coordinates(&vars->player);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	minimap(vars);
	draw_line(vars, vars->player.x_final, vars->player.y_final, 12079170);
	draw_circle(MINIMAP_WIDTH / 3, MINIMAP_HEIGHT / 3, &vars->minimap);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	render_game_splt(vars);
	return (0);
}
