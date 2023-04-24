/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:52:18 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 13:52:40 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_image(vars->mlx, vars->mc);
	mlx_destroy_image(vars->mlx, vars->bg);
	mlx_destroy_image(vars->mlx, vars->c);
	mlx_destroy_image(vars->mlx, vars->l);
	mlx_destroy_image(vars->mlx, vars->e);
	mlx_destroy_image(vars->mlx, vars->esc);
	mlx_destroy_image(vars->mlx, vars->escl);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_clear((void **)vars->map);
	free(vars->mlx);
	exit(0);
}

int	getkey(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_esc(vars);
	if (keycode == 100 || keycode == 119 || keycode == 115 || keycode == 97)
		walk(vars, keycode);
	return (0);
}

void	show_map(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars.map[y] != NULL)
	{
		x = 0;
		while (vars.map[y][x] != '\0')
		{
			if (vars.map[y][x] == '0')
				put_grass(&vars, x, y);
			else if (vars.map[y][x] == '1')
				put_tree(&vars, x, y);
			else if (vars.map[y][x] == 'P')
				put_play(&vars, x, y);
			else if (vars.map[y][x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.c,
					x * 64, y * 64);
			else if (vars.map[y][x] == 'E')
				put_ex(&vars, x, y);
			x ++;
		}
		y ++;
	}
}
