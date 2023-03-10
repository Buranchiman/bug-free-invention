/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:15 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 17:25:01 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim_r0(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f1,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f2,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f3,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f4,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f5,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f6,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f7,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f8,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	return (0);
}

int	anim_r2(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f9,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f10,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f11,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f12,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f13,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f14,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
		(vars->x + 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	return (0);
}

int	anim_l0(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf1,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf2,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf3,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf4,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf5,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf6,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf7,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf8,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	return (0);
}

int	anim_l2(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf9,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf10,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf11,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf12,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf13,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf14,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->x * 64, vars->y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
		(vars->x - 1) * 64, vars->y * 64);
	usleep(30000);
	mlx_do_sync(vars->mlx);
	return (0);
}