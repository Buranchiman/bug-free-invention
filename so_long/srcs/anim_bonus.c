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
	while (i < vars->exitr.nbframes)
	{
		if (vars->map[vars->y][vars->x] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exitcarr.f[i],
				vars->x * 64, vars->y * 64);
		else 
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exitr.f[i],
				vars->x * 64, vars->y * 64);
		if (vars->map[vars->y][vars->x + 1] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->entercarr.f[i],
				vars->x * 64, vars->y * 64);
		else if (vars->map[vars->y][vars->x + 1] == 'C' && i < 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterkeyr.f[i],
				(vars->x + 1) * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterr.f[i],
				(vars->x + 1) * 64, vars->y * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i ++;
	}
}

void	anim_l(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->exitl.nbframes)
	{
		if (vars->map[vars->y][vars->x] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exitcarl.f[i],
				vars->x * 64, vars->y * 64);
		else 
			mlx_put_image_to_window(vars->mlx, vars->win, vars->exitl.f[i],
				vars->x * 64, vars->y * 64);
		if (vars->map[vars->y][vars->x - 1] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, vars->entercarl.f[i],
				vars->x * 64, vars->y * 64);
		else if (vars->map[vars->y][vars->x - 1] == 'C' && i < 2)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterkeyr.f[i],
				(vars->x - 1) * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterl.f[i],
				(vars->x - 1) * 64, vars->y * 64);
		usleep(30000);
		mlx_do_sync(vars->mlx);
		i ++;
	}
}

void	anim_ul(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upleft.f[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upleft.f[i + 1],
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upright.f[i],
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upright.f[i + 1],
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