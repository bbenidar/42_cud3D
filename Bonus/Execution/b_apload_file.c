/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_apload_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:41:52 by bbenidar          #+#    #+#             */
/*   Updated: 2023/09/13 16:13:37 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_get_pistol_img_2(t_vars *vars)
{
	vars->pistol_img[10] = "./xpm/ak/ReasonR041694291759.xpm";
	vars->pistol_img[11] = "./xpm/ak/ReasonR051694291760.xpm";
	vars->pistol_img[12] = "./xpm/ak/ReasonR061694291760.xpm";
	vars->pistol_img[13] = "./xpm/ak/ReasonR071694291761.xpm";
	vars->pistol_img[14] = "./xpm/ak/ReasonR081694291762.xpm";
	vars->pistol_img[15] = "./xpm/ak/ReasonR091694291762.xpm";
	vars->pistol_img[16] = "./xpm/ak/ReasonR111694291764.xpm";
	vars->pistol_img[17] = "./xpm/ak/ReasonR131694291765.xpm";
	vars->pistol_img[18] = "./xpm/ak/ReasonR151694291766.xpm";
	vars->pistol_img[19] = "./xpm/ak/ReasonR171694291767.xpm";
	vars->pistol_img[20] = "./xpm/ak/ReasonR191694291768.xpm";
	vars->pistol_img[21] = "./xpm/ak/ReasonR211694291770.xpm";
	vars->pistol_img[22] = "./xpm/ak/ReasonR311694291774.xpm";
	vars->pistol_img[23] = "./xpm/ak/ReasonR321694291775.xpm";
	vars->pistol_img[24] = "./xpm/ak/ReasonR331694291775.xpm";
	vars->pistol_img[25] = "./xpm/ak/ReasonR341694291776.xpm";
	vars->pistol_img[26] = "./xpm/ak/ReasonR351694291776.xpm";
	vars->pistol_img[27] = "./xpm/ak/ReasonR361694291777.xpm";
	vars->pistol_img[28] = "./xpm/ak/ReasonR371694291777.xpm";
	vars->pistol_img[29] = 0;
}

void	ft_get_pistol_img(t_vars *vars)
{
	vars->pistol_img[0] = "./xpm/ak/Reason011694291748.xpm";
	vars->pistol_img[1] = "./xpm/ak/Reason021694291747.xpm";
	vars->pistol_img[2] = "./xpm/ak/ReasonF011694291755.xpm";
	vars->pistol_img[3] = "./xpm/ak/ReasonF021694291756.xpm";
	vars->pistol_img[4] = "./xpm/ak/ReasonF031694291756.xpm";
	vars->pistol_img[5] = "./xpm/ak/ReasonF041694291757.xpm";
	vars->pistol_img[6] = "./xpm/ak/ReasonF051694291757.xpm";
	vars->pistol_img[7] = "./xpm/ak/ReasonR011694291758.xpm";
	vars->pistol_img[8] = "./xpm/ak/ReasonR021694291758.xpm";
	vars->pistol_img[9] = "./xpm/ak/ReasonR031694291759.xpm";
	ft_get_pistol_img_2(vars);
}

void	ft_get_gun_img(t_vars *vars)
{
	vars->knife_img[0] = "./xpm/knif/Knife01.xpm";
	vars->knife_img[1] = "./xpm/knif/Knife02.xpm";
	vars->knife_img[2] = "./xpm/knif/Knife03.xpm";
	vars->knife_img[3] = "./xpm/knif/Knife04.xpm";
	vars->knife_img[4] = "./xpm/knif/Knife05.xpm";
	vars->knife_img[5] = "./xpm/knif/KnifeF01.xpm";
	vars->knife_img[6] = "./xpm/knif/KnifeF02.xpm";
	vars->knife_img[7] = "./xpm/knif/KnifeF03.xpm";
	vars->knife_img[8] = "./xpm/knif/KnifeF04.xpm";
	vars->knife_img[9] = 0;
	ft_get_pistol_img(vars);
}
