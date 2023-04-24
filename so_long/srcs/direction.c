/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:25:36 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/06 13:36:16 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maintain_dir(t_vars *vars)
{
	if (vars->dir == 0)
	{
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->esc,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->mc,
				vars->x * 64, vars->y * 64);
	}
	else
	{
		if (vars->map[vars->y][vars->x] == 'E' && vars->count != vars->items)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->escl,
				vars->x * 64, vars->y * 64);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->l,
				vars->x * 64, vars->y * 64);
	}
}

void	gps(t_map *data, int *x, int *y, char c)
{
	int	i;
	int	p;

	i = 0;
	while (data->map[i] != NULL)
	{
		p = ft_index(data->map[i], c);
		if (p != -1)
		{
			*y = i;
			*x = p;
		}
		i++;
	}
}
