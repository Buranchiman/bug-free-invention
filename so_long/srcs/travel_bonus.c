/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:14:02 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 16:29:57 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walk_r(t_vars *vars)
{
	vars->dir = 0;
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->esc,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
			vars->x * 64, vars->y * 64);
	if (vars->map[vars->y][vars->x + 1] != '1')
	{
		anim_r(vars);
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			put_ex(vars, vars->x, vars->y);
		else
			put_grass(vars, vars->x, vars->y);
		vars->x += 1;
		vars->move++;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->esc,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
				vars->x * 64, vars->y * 64);
	}
	return (0);
}

int	walk_l(t_vars *vars)
{
	vars->dir = 1;
	if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->escl,
			vars->x * 64, vars->y * 64);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
			vars->x * 64, vars->y * 64);
	if (vars->map[vars->y][vars->x - 1] != '1')
	{
		anim_l(vars);
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			put_ex(vars, vars->x, vars->y);
		else
			put_grass(vars, vars->x, vars->y);
		vars->x -= 1;
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->escl,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
				vars->x * 64, vars->y * 64);
		vars->move++;
	}
	return (0);
}

void	walk_u(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map[vars->y - 1][vars->x] != '1')
	{
		while (i <= 6)
		{
			if (vars->dir == 0)
				anim_ur(vars, i);
			else
				anim_ul(vars, i);
			i++;
			usleep(45000);
			mlx_do_sync(vars->mlx);
		}
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			put_ex(vars, vars->x, vars->y);
		else
			put_grass(vars, vars->x, vars->y);
		vars->y -= 1;
		vars->move++;
		maintain_dir(vars);
	}
}

void	walk_d(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map[vars->y + 1][vars->x] != '1')
	{
		while (i <= 6)
		{
			if (vars->dir == 0)
				anim_dr(vars, i);
			else
				anim_dl(vars, i);
			if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items
					&& i > 4)
				put_ex(vars, vars->x, vars->y);
			else if (i > 4)
				put_grass(vars, vars->x, vars->y);
			i++;
			usleep(45000);
			mlx_do_sync(vars->mlx);
		}
		vars->y += 1;
		vars->move++;
		maintain_dir(vars);
	}
}

void	walkwin(t_vars *vars, int keycode)
{
	char	*s;

	if (keycode == 100)
		walk_r(vars);
	if (keycode == 119)
		walk_u(vars);
	if (keycode == 115)
		walk_d(vars);
	if (keycode == 97)
		walk_l(vars);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0xccccff, "Numbers of move =");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, 192, 0);
	s = ft_itoa(vars->move);
	mlx_string_put(vars->mlx, vars->win, 195, 32, 0xccccff, s);
	free(s);
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->map[vars->y][vars->x] = '0';
		vars->count += 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count == vars->items)
	{
		ft_printf("He pulled up !\nYou won !");
		close_all(vars);
	}
}
