/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parsing_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:04:40 by moudrib           #+#    #+#             */
/*   Updated: 2023/09/14 10:59:52 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	*create_rgb_arr(int r, int g, int b)
{
	int	*rgb;

	if (!(r >= 0 && r < 256) || !(g >= 0 && g < 256) || !(b >= 0 && b < 256))
		return (NULL);
	rgb = malloc(4 * sizeof(int));
	if (!rgb)
		return (NULL);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	rgb[3] = 0;
	return (rgb);
}

int	count_elements(t_vars *vars, t_counter *count)
{
	while (vars->tmp)
	{
		if (ft_strlen(vars->tmp->element) > 3)
			return (1);
		if (!ft_strcmp(vars->tmp->element, "C "))
			count->ceiling++;
		else if (!ft_strcmp(vars->tmp->element, "F "))
			count->floor++;
		else if (!ft_strcmp(vars->tmp->element, "NO "))
			count->north++;
		else if (!ft_strcmp(vars->tmp->element, "SO "))
			count->south++;
		else if (!ft_strcmp(vars->tmp->element, "WE "))
			count->west++;
		else if (!ft_strcmp(vars->tmp->element, "EA "))
			count->east++;
		vars->tmp = vars->tmp->link;
	}
	return (0);
}

int	check_rgb_values(t_infos *infos)
{
	t_vars	vars;

	vars.tmp = infos;
	while (vars.tmp)
	{
		vars.i = -1;
		if (vars.tmp->element[0] == 'F' || vars.tmp->element[0] == 'C')
		{
			if (count_commas(vars.tmp->value) > 2)
				return (1);
			vars.arr = ft_split(vars.tmp->value, ',');
			while (vars.arr[++vars.i])
				if (ft_isdigit(vars.arr[vars.i]))
					return (1);
			if (vars.i == 3)
				vars.tmp->rgb = create_rgb_arr(ft_atoi(vars.arr[0]),
						ft_atoi(vars.arr[1]), ft_atoi(vars.arr[2]));
			if (!vars.tmp->rgb)
				return (1);
			ft_free_arr(vars.arr);
		}
		vars.tmp = vars.tmp->link;
	}
	return (0);
}

int	check_missing_or_duplicated_element(t_infos **infos, t_vars *vars)
{
	t_counter	count;

	count.east = 0;
	count.west = 0;
	count.north = 0;
	count.south = 0;
	count.floor = 0;
	count.ceiling = 0;
	vars->tmp = *infos;
	if (count_elements(vars, &count))
		return (1);
	if (count.ceiling != 1 || count.floor != 1 || count.north != 1
		|| count.south != 1 || count.east != 1 || count.west != 1)
		return (1);
	if (check_rgb_values(*infos))
		return (1);
	return (0);
}

void	check_if_informations_are_valid(t_vars *vars)
{
	vars->i = -1;
	vars->infos = NULL;
	while (vars->elements[++vars->i])
	{
		vars->arr = malloc(3 * sizeof(char *));
		if (!vars->arr)
			return ;
		vars->length = ft_strlen(vars->elements[vars->i]);
		if (vars->elements[vars->i][0] == 'F'
				|| vars->elements[vars->i][0] == 'C')
			vars->flag = 2;
		else
			vars->flag = 3;
		vars->arr[0] = ft_substr(vars->elements[vars->i], 0, vars->flag);
		vars->arr[1] = ft_substr(vars->elements[vars->i], vars->flag,
				vars->length);
		vars->arr[2] = 0;
		ft_lstadd_back(&vars->infos, ft_lstnew(ft_strdup(vars->arr[0]),
				ft_strdup(vars->arr[1])));
		ft_free_arr(vars->arr);
	}
	if (check_missing_or_duplicated_element(&vars->infos, vars))
		ft_error(5, 0, 0, 0);
	ft_free_arr(vars->elements);
}
