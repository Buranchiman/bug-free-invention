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

void	anim_r(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->esc,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
			vars->x * 64, vars->y * 64);
	while (i < 14)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f[i + 1],
			(vars->x + 1) * 64, vars->y * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i = i +2;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
}

void	anim_l(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->escl,
				vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
			vars->x * 64, vars->y * 64);
	while (i < 14)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.lf[i + 1],
			(vars->x - 1) * 64, vars->y * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i = i +2;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
}

void	anim_ul(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.ul[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.ul[i + 1],
			vars->x * 64, (vars->y - 1) * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i = i +2;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x * 64, vars->y * 64);	
}

void	anim_ur(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.ur[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.ur[i + 1],
			vars->x * 64, (vars->y - 1) * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i = i +2;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->x * 64, vars->y * 64);
}