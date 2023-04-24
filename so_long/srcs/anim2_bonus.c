/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:34:25 by wvallee           #+#    #+#             */
/*   Updated: 2023/04/24 15:00:47 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_dr(t_vars *vars, int i)
{
	if (vars->map[vars->y][vars->x] == 'E' && i < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exitcarrdown.f[i], vars->x * 64, vars->y * 64);
	}
	else if (i < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitdownr.f[i],
			vars->x * 64, vars->y * 64);
	}
	if (vars->map[vars->y + 1][vars->x] == 'E' && i >= 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->entercarrdown.f[i - 1], vars->x * 64, (vars->y + 1) * 64);
	}
	else if (vars->map[vars->y + 1][vars->x] == 'C' && i >= 1 && i < 4)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->downrkey.f[i - 1],
			vars->x * 64, (vars->y + 1) * 64);
	}
	else if (i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enterdownr.f[i - 1],
			vars->x * 64, (vars->y + 1) * 64);
	}
}

void	anim_dl(t_vars *vars, int i)
{
	if (vars->map[vars->y][vars->x] == 'E' && i < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitcarldown.f[i],
			vars->x * 64, vars->y * 64);
	}
	else if (i < 5)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitdownl.f[i],
			vars->x * 64, vars->y * 64);
	}
	if (vars->map[vars->y + 1][vars->x] == 'E' && i >= 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->entercarldown.f[i - 1], vars->x * 64, (vars->y + 1) * 64);
	}
	else if (vars->map[vars->y + 1][vars->x] == 'C' && i >= 1 && i < 4)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->downlkey.f[i - 1],
			vars->x * 64, (vars->y + 1) * 64);
	}
	else if (i > 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enterdownl.f[i - 1],
			vars->x * 64, (vars->y + 1) * 64);
	}
}

int	inithorizontal(t_vars *vars)
{
	if (startframe(vars, &(vars->exitr), "exitr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterr), "enterr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarr), "exitcarr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarr), "entercarr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterkeyr), "enterkeyr", 2) == 0)
		return (0);
	if (startframe(vars, &(vars->exitl), "exitl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterl), "enterl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarl), "exitcarl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarl), "entercarl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterkeyl), "enterkeyl", 2) == 0)
		return (0);
	return (1);
}

int	initup(t_vars *vars)
{
	if (startframe(vars, &(vars->exitupr), "exitupr", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->enterupr), "enterupr", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarupr), "exitcarupr", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarupr), "entercarupr", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->upkeyr), "upkeyr", 3) == 0)
		return (0);
	if (startframe(vars, &(vars->exitupl), "exitupl", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->enterupl), "enterupl", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarupl), "exitcarupl", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarupl), "entercarupl", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->upkeyl), "upkeyl", 3) == 0)
		return (0);
	return (1);
}

int	initdown(t_vars *vars)
{
	if (startframe(vars, &(vars->exitdownr), "exitdownr", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->enterdownr), "enterdownr", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarrdown), "exitcarrdown", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarrdown), "entercarrdown", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->downrkey), "downrkey", 3) == 0)
		return (0);
	if (startframe(vars, &(vars->exitdownl), "exitdownl", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->enterdownl), "enterdownl", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarldown), "exitcarldown", 5) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarldown), "entercarldown", 6) == 0)
		return (0);
	if (startframe(vars, &(vars->downlkey), "downlkey", 3) == 0)
		return (0);
	return (1);
}
