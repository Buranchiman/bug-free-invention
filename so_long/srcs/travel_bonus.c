/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:14:02 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/06 13:14:24 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void walk(t_vars *vars, int keycode)
{
	if (keycode == 100)
		walk_right(vars);
	if (keycode == 119)
		walk_up(vars);
	if (keycode == 115)
		walk_down(vars);
	if (keycode == 97)
		walk_left(vars);
	vars->move ++;
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0xccccff, "Numbers of move =");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->bg, 128, 0);
	mlx_string_put(vars->mlx, vars->win, 160, 32, 0xccccff, ft_itoa(vars->move));
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->map[vars->y][vars->x] = '0';
		vars->count += 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->count == vars->items)
	{
		ft_printf("He pulled up !\nYou won !");
		close_esc(vars);
	}
}
