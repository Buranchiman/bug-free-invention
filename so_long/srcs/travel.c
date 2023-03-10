/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:51:27 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 12:14:24 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_right(t_vars *vars)
{
	vars->dir = 0;
	if (vars->map[vars->y][vars->x + 1] != '1')
	{
		vars->move++;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
		vars->x += 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->esc,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
			vars->x * 64, vars->y * 64);
}

void	walk_left(t_vars *vars)
{
	vars->dir = 1;
	if (vars->map[vars->y][vars->x - 1] != '1')
	{
		vars->move++;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
		vars->x -= 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->escl,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
			vars->x * 64, vars->y * 64);
}

void	walk_up(t_vars *vars)
{
	if (vars->map[vars->y - 1][vars->x] != '1')
	{
		vars->move++;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
		vars->y -= 1;
		maintain_dir(vars);
	}
}

void	walk_down(t_vars *vars)
{
	if (vars->map[vars->y + 1][vars->x] != '1')
	{
		vars->move++;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->e,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
				vars->x * 64, vars->y * 64);
		vars->y += 1;
		maintain_dir(vars);
	}
}

void	walk(t_vars *vars, int keycode)
{
	if (keycode == 100)
		walk_right(vars);
	if (keycode == 119)
		walk_up(vars);
	if (keycode == 115)
		walk_down(vars);
	if (keycode == 97)
		walk_left(vars);
	ft_printf("\rnumber of moves is %d", vars->move);
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->map[vars->y][vars->x] = '0';
		vars->count += 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count == vars->items)
	{
		ft_printf("\nHe pulled up !\nYou won !");
		close_esc(vars);
	}
}
