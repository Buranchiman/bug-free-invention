/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbeg_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:03:30 by wvallee           #+#    #+#             */
/*   Updated: 2023/04/24 15:00:21 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gameover(t_vars *vars, char c)
{
	if ((vars->x + 1 == vars->topx && vars->y == vars->topy && c == 'r')
		|| (vars->x - 1 == vars->topx && vars->y == vars->topy && c == 'l')
		|| (vars->x == vars->topx && vars->y + 1 == vars->topy && c == 'd')
		|| (vars->x == vars->topx && vars->y - 1 == vars->topy && c == 'u'))
	{
		ft_printf("Game over !\nThe TopG caught you");
		close_all(vars);
	}
}

void	close_anim(t_vars *vars, t_frames frames)
{
	int	i;

	i = 0;
	while (i < frames.nbframes)
	{
		mlx_destroy_image(vars->mlx, frames.f[i]);
		i ++;
	}
	free(frames.f);
}

void	close1(t_vars *vars)
{
	close_anim(vars, vars->exitr);
	close_anim(vars, vars->enterr);
	close_anim(vars, vars->exitcarr);
	close_anim(vars, vars->entercarr);
	close_anim(vars, vars->enterkeyr);
	close_anim(vars, vars->exitl);
	close_anim(vars, vars->enterl);
	close_anim(vars, vars->exitcarl);
	close_anim(vars, vars->entercarl);
	close_anim(vars, vars->enterkeyl);
	close_anim(vars, vars->exitupr);
	close_anim(vars, vars->enterupr);
	close_anim(vars, vars->exitcarupr);
	close_anim(vars, vars->entercarupr);
	close_anim(vars, vars->upkeyr);
	close_anim(vars, vars->exitupl);
	close_anim(vars, vars->enterupl);
	close_anim(vars, vars->exitcarupl);
	close_anim(vars, vars->entercarupl);
	close_anim(vars, vars->upkeyl);
	close_anim(vars, vars->exitdownl);
	close_anim(vars, vars->enterdownl);
	close_anim(vars, vars->exitcarldown);
	close_anim(vars, vars->entercarldown);
	close_anim(vars, vars->downlkey);
}
