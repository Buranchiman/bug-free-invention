/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:16:36 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/01 16:04:07 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*mc;
}				t_vars;

int close_esc(int keycode, t_vars *vars, void *purple_id)
{
	printf("key=======[%d]\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_image(vars->mlx, vars->mc);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
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

int main(void)
{
	t_vars	vars;
	int		widthG;
	int		heightG;
	int		widthP;
	int		heightP;
	int x;
	int y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_loooong");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "blue-floor.xpm", &widthG, &heightG);
	vars.mc = mlx_xpm_file_to_image(vars.mlx, "knight_idle_anim_f0.xpm", &widthP, &heightP);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x, y);
			x += 16;
		}
		y += 16;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.mc, 0, 0);
	mlx_key_hook(vars.win, close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, close_cross, &vars);
	mlx_loop(vars.mlx);
}
