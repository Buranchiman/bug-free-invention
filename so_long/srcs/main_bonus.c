/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:16:10 by wvallee           #+#    #+#             */
/*   Updated: 2023/04/24 14:57:54 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcharbonus(char *map)
{
	unsigned int	j;

	j = 0;
	while (map[j] != '\0')
	{
		if (map[j] != '0' && map[j] != '1' && map[j] != 'P'
			&& map[j] != 'C' && map[j] != 'E' && map[j] != '\n'
			&& map[j] != 'X')
		{
			ft_printf("Error !\nInvalid character found while parsing\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	checkbonus(char *name, t_map *data)
{
	if (checkformat(name, ".ber") == 0)
		return (0);
	if (get_map(data) == 0)
		return (0);
	if (checkcharbonus(data->buffer) == 0)
	{
		free(data->buffer);
		ft_clear((void **)data->map);
		return (0);
	}
	if (checkwalls(data) == 0)
	{
		ft_clear((void **)data->map);
		free(data->buffer);
		ft_printf("Error\nThe map isn't surrounded by walls\n");
		return (0);
	}
	if (countelem(data) == -1)
	{
		ft_printf("Error\nIncorrect number of Exit/Collectible/Start point\n");
		return (0);
	}
	gps(data, &data->topx, &data->topy, 'X');
	return (1);
}

int	close_all(t_vars *vars)
{
	close1(vars);
	mlx_do_sync(vars->mlx);
	close_anim(vars, vars->exitdownr);
	close_anim(vars, vars->enterdownr);
	close_anim(vars, vars->exitcarrdown);
	close_anim(vars, vars->entercarrdown);
	close_anim(vars, vars->downrkey);
	mlx_destroy_image(vars->mlx, vars->tate);
	mlx_do_sync(vars->mlx);
	close_esc(vars);
	exit(0);
	return (0);
}

int	getkeyb(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		close_all(vars);
	}
	if (keycode == 100 || keycode == 119 || keycode == 115 || keycode == 97)
		walkwin(vars, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_map		data;

	data.nb = 0;
	data.size = 0;
	if (argc != 2)
		return (0);
	data.name = argv[1];
	vars.move = 0;
	vars.dir = 0;
	vars.count = 0;
	if (checkbonus(data.name, &data) == 0)
		return (0);
	if (checking(&data) == 0)
		return (0);
	vars_init(&vars, &data);
	if (initframes(&vars) == 0)
		close_all(&vars);
	show_map(vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.tate,
		vars.topx * 64, vars.topy * 64);
	mlx_set_font(vars.mlx, vars.win, "9x15bold");
	mlx_key_hook(vars.win, getkeyb, &vars);
	mlx_hook(vars.win, 17, 0L, close_all, &vars);
	mlx_loop(vars.mlx);
}
