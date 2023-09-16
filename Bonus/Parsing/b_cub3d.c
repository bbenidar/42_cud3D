/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cub3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:38:45 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/14 15:25:26 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_size_of_map_array(int map_fd)
{
	int		flag;
	int		size;
	char	*line;

	size = 0;
	flag = 0;
	line = ft_get_next_line(map_fd);
	while (line)
	{
		if (is_printable(line))
			flag = 1;
		if (flag == 1)
			size++;
		free(line);
		line = ft_get_next_line(map_fd);
	}
	return (size);
}

char	**copy_the_map_from_file_to_2d_array(char *file_path, int map_fd)
{
	t_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.size = get_size_of_map_array(map_fd);
	map_fd = open(file_path, O_RDONLY);
	if (map_fd < 0)
		ft_error(4, 0, 0, 0);
	vars.map = malloc(sizeof(char *) * (vars.size + 1));
	if (!vars.map)
		return (0);
	vars.line = ft_get_next_line(map_fd);
	if (!vars.line)
		ft_error(10, 0, 0, 0);
	while (vars.line)
	{
		if (is_printable(vars.line))
			vars.j++;
		if (vars.j > 6)
			vars.map[vars.i++] = ft_strtrim(vars.line, "\n");
		free(vars.line);
		vars.line = ft_get_next_line(map_fd);
	}
	vars.map[vars.i] = 0;
	return (vars.map);
}

void	read_file_and_get_informations(char *file_path, t_vars *vars)
{
	char	*line;

	vars->map_fd = open(file_path, O_RDONLY);
	if (vars->map_fd < 0)
		ft_error(4, 0, 0, 0);
	vars->elements = malloc(7 * sizeof(char *));
	if (!vars->elements)
		return ;
	line = ft_get_next_line(vars->map_fd);
	if (!line)
		ft_error(10, 0, 0, 0);
	vars->i = 0;
	while (line)
	{
		if (is_printable(line) && vars->i < 6)
			vars->elements[vars->i++] = ft_substr(line, 0, ft_strlen(line) - 1);
		free(line);
		vars->elements[vars->i] = 0;
		if (vars->i == 6)
			break ;
		line = ft_get_next_line(vars->map_fd);
	}
	check_if_informations_are_valid(vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	first_checks(ac);
	vars = malloc(sizeof(t_vars));
	vars->weapon = KNIFE;
	vars->hid_mouse = 1;
	vars->fire = 0;
	if (!vars)
		return (0);
	if (check_valid_extension(av[1]))
		ft_error(3, 0, 0, 0);
	read_file_and_get_informations(av[1], vars);
	vars->map = copy_the_map_from_file_to_2d_array(av[1], vars->map_fd);
	if (!general_map_check(vars->map))
		exit(1);
	open_window(vars);
	mlx_loop_hook(vars->mlx, render_game, vars);
	mlx_hook(vars->mlx_win, 2, 0, key_press, vars);
	mlx_hook(vars->mlx_win, 3, 0, key_release, vars);
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	mlx_hook(vars->mlx_win, 6, 0, &mouse_event, vars);
	mlx_hook(vars->mlx_win, 4, 0, &mouse_press, vars);
	mlx_loop(vars->mlx);
	free_data(&vars->infos, NULL, vars->map);
	return (free(vars), 0);
}
