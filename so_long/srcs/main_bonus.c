/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:16:10 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 17:11:10 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	getkeyb(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_esc(vars);
	if (keycode == 100 || keycode == 119 || keycode == 115 || keycode == 97)
		walkwin(vars, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		data;

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
	initframes(&vars);
	mlx_set_font(vars.mlx, vars.win, "9x15bold");
	mlx_key_hook(vars.win, getkeyb, &vars);
	mlx_hook(vars.win, 17, 0L, close_esc, &vars);
	mlx_loop(vars.mlx);
}