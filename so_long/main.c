/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:16:36 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/20 12:13:19 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "mlx.h"
#include <stdlib.h>

void close_esc(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_image(vars->mlx, vars->mc);
	mlx_destroy_image(vars->mlx, vars->bg);
	mlx_destroy_image(vars->mlx, vars->c);
	mlx_destroy_image(vars->mlx, vars->l);
	mlx_destroy_image(vars->mlx, vars->e);
	mlx_destroy_image(vars->mlx, vars->esc);
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


int close_cross(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);	
	exit(0);
}

int main(int argc, char **argv)
{
	t_vars	vars = {.mlx = NULL, .win = NULL, .img = NULL, .bg = NULL, .mc = NULL, .l = NULL, .c = NULL, .e = NULL, .esc = NULL, .escl = NULL, .x = 0, .y = 0, .move = 0, .count = 0, .items = 0, .map = NULL};
	t_map	data = {.nb = 0, .size = 0, .name = argv[1], .map = NULL, .buffer = NULL, .x = 0, .y = 0, .items = 0, .count = 0, .error = 0 };
	int		widthG;
	int		heightG;
	int		widthP;
	int		heightP;
	int		widthT;
	int		heightT;
	int x;
	int y;
	int i;

	if (argc != 2)
		return (0);
	y = 0;
	i = 0;
	data = checking(data.name, data);
	if (data.error == 1)
	{
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 64 * (data.size - 1), 64 * data.nb, "so_loooong");
		vars.img = mlx_xpm_file_to_image(vars.mlx, "realgrass.xpm", &widthG, &heightG);
		vars.bg = mlx_xpm_file_to_image(vars.mlx, "oaktree.xpm", &widthT, &heightT);
		vars.mc = mlx_xpm_file_to_image(vars.mlx, "pullup0.xpm", &widthP, &heightP);
		vars.l = mlx_xpm_file_to_image(vars.mlx, "pullupl0.xpm", &widthP, &heightP);
		vars.c = mlx_xpm_file_to_image(vars.mlx, "Collectible.xpm", &widthP, &heightP);
		vars.e = mlx_xpm_file_to_image(vars.mlx, "TopG.xpm", &widthP, &heightP);
		vars.esc =  mlx_xpm_file_to_image(vars.mlx, "pullingup.xpm", &widthP, &heightP);
		vars.escl =  mlx_xpm_file_to_image(vars.mlx, "pullingupl.xpm", &widthP, &heightP);
		vars.map = ft_split(data.buffer, '\n');
		vars.x = data.x;
		vars.y = data.y;
		vars.items = data.items - 1;
		free(data.buffer);
		ft_clear(data.map);
		while (vars.map[y] != NULL)
		{
			x = 0;
			while (vars.map[y][x] != '\0')
			{
				if (vars.map[y][x] == '0')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x * 64, y * 64);
				else if (vars.map[y][x] == '1')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.bg, x * 64, y * 64);
				else if (vars.map[y][x] == 'P')
				{
					mlx_put_image_to_window(vars.mlx, vars.win, vars.mc, x * 64, y * 64);
				}
				else if (vars.map[y][x] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.c, x * 64, y * 64);
				else if (vars.map[y][x] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.e, x * 64, y * 64);
				x ++;
			}
			y ++;
		}
		mlx_key_hook(vars.win, getkey, &vars);
		mlx_hook(vars.win, 17, 0L, close_cross, &vars);
		mlx_loop(vars.mlx);
	}
}
