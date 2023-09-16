/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:34:50 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/14 14:45:02 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_name_texture(t_vars *vars)
{
	t_infos	*tmp;

	tmp = vars->infos;
	while (tmp)
	{
		if (tmp->element[0] == 'N')
			vars->img_no = tmp->value;
		else if (tmp->element[0] == 'W')
			vars->img_we = tmp->value;
		else if (tmp->element[0] == 'S')
			vars->img_so = tmp->value;
		else if (tmp->element[0] == 'E')
			vars->img_ea = tmp->value;
		tmp = tmp->link;
	}
}

void	ft_texture_split(t_vars *vars)
{
	int		bits_per_pixel;
	int		endian;

	vars->image.no_img = mlx_get_data_addr(vars->no_ptr,
			&bits_per_pixel, &vars->image.no_line, &endian);
	vars->image.we_img = mlx_get_data_addr(vars->we_ptr,
			&bits_per_pixel, &vars->image.we_line, &endian);
	vars->image.so_img = mlx_get_data_addr(vars->so_ptr,
			&bits_per_pixel, &vars->image.so_line, &endian);
	vars->image.ea_img = mlx_get_data_addr(vars->ea_ptr,
			&bits_per_pixel, &vars->image.ea_line, &endian);
	if (!vars->image.no_img || !vars->image.we_img)
		ft_error(10, 0, 0, 0);
}

void	ft_texture(t_vars *vars)
{
	ft_get_name_texture(vars);
	vars->no_ptr = mlx_xpm_file_to_image(vars->mlx, vars->img_no,
			&vars->xpm_width, &vars->xpm_height);
	if (vars->xpm_height * vars->xpm_width > (720 * 720))
		ft_error(10, 0, 0, 0);
	vars->we_ptr = mlx_xpm_file_to_image(vars->mlx, vars->img_we,
			&vars->xpm_width2, &vars->xpm_height2);
	if (vars->xpm_height2 * vars->xpm_width2 > (720 * 720))
		ft_error(10, 0, 0, 0);
	vars->so_ptr = mlx_xpm_file_to_image(vars->mlx, vars->img_so,
			&vars->xpm_width3, &vars->xpm_height3);
	if (vars->xpm_height3 * vars->xpm_width3 > (720 * 720))
		ft_error(10, 0, 0, 0);
	vars->ea_ptr = mlx_xpm_file_to_image(vars->mlx, vars->img_ea,
			&vars->xpm_width4, &vars->xpm_height4);
	if (vars->xpm_height2 * vars->xpm_width2 > (720 * 720))
		ft_error(10, 0, 0, 0);
	if (vars->xpm_height4 * vars->xpm_width4 > (720 * 720))
		ft_error(10, 0, 0, 0);
	if (!vars->no_ptr || !vars->we_ptr || !vars->so_ptr || !vars->ea_ptr)
		ft_error(10, 0, 0, 0);
	ft_texture_split(vars);
}

int	position_f(int x, int y, int line)
{
	int	position;

	position = abs((x * (4)) + (y * line));
	return (position);
}

int	draw_pixels_image(t_img *img, int x, int y, int flag)
{
	char	*pixel;

	if (x < 0 || y < 0 || y >= WINDOW_HEIGHT || x >= WINDOW_WIDTH)
		return (0);
	if (flag == 1)
		pixel = img->no_img + position_f(x, y, img->no_line);
	else if (flag == 2)
		pixel = img->we_img + position_f(x, y, img->we_line);
	else if (flag == 3)
		pixel = img->so_img + position_f(x, y, img->so_line);
	else
		pixel = img->ea_img + position_f(x, y, img->ea_line);
	return (*(unsigned int *)pixel);
}
