/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:21:13 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 17:11:58 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initframes(t_vars *vars)
{
	initframesr(vars);
	initframesl(vars);
}

void	initframesr(t_vars *vars)
{
	int	l;
	int	h;

	vars->frames.f1 = mlx_xpm_file_to_image(vars->mlx, "xpm/f1.xpm", &l, &h);
	vars->frames.f2 = mlx_xpm_file_to_image(vars->mlx, "xpm/f2.xpm", &l, &h);
	vars->frames.f3 = mlx_xpm_file_to_image(vars->mlx, "xpm/f3.xpm", &l, &h);
	vars->frames.f4 = mlx_xpm_file_to_image(vars->mlx, "xpm/f4.xpm", &l, &h);
	vars->frames.f5 = mlx_xpm_file_to_image(vars->mlx, "xpm/f5.xpm", &l, &h);
	vars->frames.f6 = mlx_xpm_file_to_image(vars->mlx, "xpm/f6.xpm", &l, &h);
	vars->frames.f7 = mlx_xpm_file_to_image(vars->mlx, "xpm/f7.xpm", &l, &h);
	vars->frames.f8 = mlx_xpm_file_to_image(vars->mlx, "xpm/f8.xpm", &l, &h);
	vars->frames.f9 = mlx_xpm_file_to_image(vars->mlx, "xpm/f9.xpm", &l, &h);
	vars->frames.f10 = mlx_xpm_file_to_image(vars->mlx, "xpm/f10.xpm", &l, &h);
	vars->frames.f11 = mlx_xpm_file_to_image(vars->mlx, "xpm/f11.xpm", &l, &h);
	vars->frames.f12 = mlx_xpm_file_to_image(vars->mlx, "xpm/f12.xpm", &l, &h);
	vars->frames.f13 = mlx_xpm_file_to_image(vars->mlx, "xpm/f13.xpm", &l, &h);
	vars->frames.f14 = mlx_xpm_file_to_image(vars->mlx, "xpm/f14.xpm", &l, &h);
}

void	initframesl(t_vars *vars)
{
	int	l;
	int	h;

	vars->frames.lf1 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf1.xpm", &l, &h);
	vars->frames.lf2 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf2.xpm", &l, &h);
	vars->frames.lf3 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf3.xpm", &l, &h);
	vars->frames.lf4 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf4.xpm", &l, &h);
	vars->frames.lf5 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf5.xpm", &l, &h);
	vars->frames.lf6 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf6.xpm", &l, &h);
	vars->frames.lf7 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf7.xpm", &l, &h);
	vars->frames.lf8 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf8.xpm", &l, &h);
	vars->frames.lf9 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf9.xpm", &l, &h);
	vars->frames.lf10 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf10.xpm", &l, &h);
	vars->frames.lf11 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf11.xpm", &l, &h);
	vars->frames.lf12 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf12.xpm", &l, &h);
	vars->frames.lf13 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf13.xpm", &l, &h);
	vars->frames.lf14 = mlx_xpm_file_to_image(vars->mlx, "xpm/lf14.xpm", &l, &h);
}