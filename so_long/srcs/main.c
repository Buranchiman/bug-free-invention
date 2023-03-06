/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:16:36 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/06 16:38:04 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	close_esc(t_vars *vars)
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
	ft_clear(vars->map);
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

int	close_cross(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
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
				put_grass(vars, x, y);
			else if (vars.map[y][x] == '1')
				put_tree(vars, x, y);
			else if (vars.map[y][x] == 'P')
				put_play(vars, x, y);
			else if (vars.map[y][x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.c,
					x * 64, y * 64);
			else if (vars.map[y][x] == 'E')
				put_ex(vars, x, y);
			x ++;
		}
		y ++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	data;

	if (argc != 2)
		return (0);
	data.name = argv[1];
	vars.move = 0;
	vars.dir = 0;
	vars.count = 0;
	if (checking(data.name, &data) == 0)
		return (0);
	vars_init(&vars, &data);
	show_map(vars);
	mlx_key_hook(vars.win, getkey, &vars);
	mlx_hook(vars.win, 17, 0L, close_cross, &vars);
	mlx_loop(vars.mlx);
}
