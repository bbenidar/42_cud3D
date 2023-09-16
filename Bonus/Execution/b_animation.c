/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_animation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:55:31 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/13 21:08:06 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	player_pistl_animation_3(t_vars *vars, int *count)
{
	int	x;
	int	y;

	if (*count >= 0 && *count <= 10)
		vars->rec = mlx_xpm_file_to_image(vars->mlx,
				vars->pistol_img[0], &x, &y);
	else
	{
		vars->rec = mlx_xpm_file_to_image(vars->mlx,
				vars->pistol_img[1], &x, &y);
		*count = 0;
	}
}

void	player_pistl_animation_2(t_vars *vars, int *count)
{
	int	x;
	int	y;

	if (vars->fire == 1 && vars->amo > 0)
	{
		if (count >= 0 && *count <= 8)
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->pistol_img[*count / 2], &x, &y);
		else
		{
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->pistol_img[6], &x, &y);
			vars->fire = 0;
			*count = 0;
			vars->amo--;
		}
	}
	else
		player_pistl_animation_3(vars, count);
}

void	player_pistl_animation(t_vars *vars)
{
	static int	count;
	int			x;
	int			y;

	if (vars->fire == 3 && vars->ammo_full > 0)
	{
		if (count >= 0 && count <= 42)
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->pistol_img[count / 2], &x, &y);
		else
		{
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->pistol_img[28], &x, &y);
			vars->fire = 0;
			count = 0;
		}
	}
	else
		player_pistl_animation_2(vars, &count);
	if (!vars->rec)
	{
		write(1, "img not found\n", 15);
		exit (1);
	}
	count++;
}

void	player_animation_2(t_vars *vars, int *count)
{
	int	x;
	int	y;

	if (*count >= 0 && *count <= 16)
		vars->rec = mlx_xpm_file_to_image(vars->mlx,
				vars->knife_img[*count / 2], &x, &y);
	else
	{
		vars->rec = mlx_xpm_file_to_image(vars->mlx,
				vars->knife_img[8], &x, &y);
		vars->fire = 0;
		*count = 0;
	}
}

void	player_animation(t_vars *vars)
{
	int			x;
	int			y;
	static int	count;

	if (vars->fire == 0 || vars->fire == 3)
	{
		if (count >= 0 && count <= 16)
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->knife_img[count / 4], &x, &y);
		else
		{
			vars->rec = mlx_xpm_file_to_image(vars->mlx,
					vars->knife_img[4], &x, &y);
			count = 0;
		}
	}
	else
		player_animation_2(vars, &count);
	if (!vars->rec)
	{
		write(1, "img not found\n", 15);
		exit (1);
	}
	count++;
}
