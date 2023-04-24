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
				(vars->x + 1) * 64, vars->y * 64);
		else if (vars->map[vars->y][vars->x + 1] == 'C' && i < 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterkeyr.f[i],
				(vars->x + 1) * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterr.f[i],
				(vars->x + 1) * 64, vars->y * 64);
		usleep(45000);
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
				(vars->x - 1) * 64, vars->y * 64);
		else if (vars->map[vars->y][vars->x - 1] == 'C' && i < 2)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterkeyr.f[i],
				(vars->x - 1) * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->enterl.f[i],
				(vars->x - 1) * 64, vars->y * 64);
		usleep(45000);
		mlx_do_sync(vars->mlx);
		i ++;
	}
}

void	anim_ur(t_vars *vars, int i)
{
	if (vars->map[vars->y][vars->x] == 'E' && i <= 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitcarupr.f[i],
			vars->x * 64, vars->y * 64);
	}
	else if (i <= 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitupr.f[i],
			vars->x * 64, vars->y * 64);
	}
	if (vars->map[vars->y - 1][vars->x] == 'E' && i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->entercarupr.f[i - 2], vars->x * 64, (vars->y - 1) * 64);
	}
	else if (vars->map[vars->y - 1][vars->x] == 'C' && i > 1 && i < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upkeyr.f[i - 2],
			vars->x * 64, (vars->y - 1) * 64);
	}
	else if (i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enterupr.f[i - 2], vars->x * 64, (vars->y - 1) * 64);
	}
}

void	anim_ul(t_vars *vars, int i)
{
	if (vars->map[vars->y][vars->x] == 'E' && i <= 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitcarupl.f[i],
			vars->x * 64, vars->y * 64);
	}
	else if (i <= 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitupl.f[i],
			vars->x * 64, vars->y * 64);
	}
	if (vars->map[vars->y - 1][vars->x] == 'E' && i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->entercarupl.f[i - 2], vars->x * 64, (vars->y - 1) * 64);
	}
	else if (vars->map[vars->y - 1][vars->x] == 'C' && i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->upkeyl.f[i - 2],
			vars->x * 64, (vars->y - 1) * 64);
	}
	else if (i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enterupl.f[i - 2], vars->x * 64, (vars->y - 1) * 64);
	}
}
