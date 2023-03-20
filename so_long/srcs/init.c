/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:24:03 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/06 16:54:17 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	vars_init(t_vars *vars, t_map *data)
{
	int	l;
	int	h;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			64 * (data->size - 1), 64 * data->nb, "so_loooong");
	vars->img = mlx_xpm_file_to_image(vars->mlx, "xpm/grass.xpm", &l, &h);
	vars->bg = mlx_xpm_file_to_image(vars->mlx, "xpm/tree.xpm", &l, &h);
	vars->mc = mlx_xpm_file_to_image(vars->mlx, "xpm/pullup0.xpm", &l, &h);
	vars->l = mlx_xpm_file_to_image(vars->mlx, "xpm/pullupl0.xpm", &l, &h);
	vars->c = mlx_xpm_file_to_image(vars->mlx, "xpm/Keys.xpm", &l, &h);
	vars->e = mlx_xpm_file_to_image(vars->mlx, "xpm/TopG.xpm", &l, &h);
	vars->esc = mlx_xpm_file_to_image(vars->mlx, "xpm/escr.xpm", &l, &h);
	vars->escl = mlx_xpm_file_to_image(vars->mlx, "xpm/escl.xpm", &l, &h);
	vars->map = ft_split(data->buffer, '\n');
	vars->x = data->x;
	vars->y = data->y;
	vars->items = data->items - 1;
	free(data->buffer);
	ft_clear(data->map);
}

void	put_grass(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x * 64, y * 64);
}

void	put_tree(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, vars.bg, x * 64, y * 64);
}

void	put_play(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, vars.mc, x * 64, y * 64);
}

void	put_ex(t_vars vars, int x, int y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, vars.e, x * 64, y * 64);
}
