/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:13:38 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 15:45:56 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"
# include "mlx.h"

typedef struct	s_map
{
	unsigned int    nb;
	unsigned int    size;
    char			*name;
	char			**map;
	char			*buffer;
	unsigned int	x;
	unsigned int	y;
	int				items;
	int				count;
}				t_map;

typedef struct s_frames
{
	void	*f1;
	void	*f2;
	void	*f3;
	void	*f4;
	void	*f5;
	void	*f6;
	void	*f7;
	void	*f8;
	void	*f9;
	void	*f10;
	void	*f11;
	void	*f12;
	void	*f13;
	void	*f14;
	void	*lf1;
	void	*lf2;
	void	*lf3;
	void	*lf4;
	void	*lf5;
	void	*lf6;
	void	*lf7;
	void	*lf8;
	void	*lf9;
	void	*lf10;
	void	*lf11;
	void	*lf12;
	void	*lf13;
	void	*lf14;
}				t_frames;

typedef struct s_vars
{
	t_frames	frames;
	void		*mlx;
	void		*win;
	void		*img;
	void		*bg;
	void		*mc;
	void 		*l;
	void		*c;
	void		*e;
	void		*esc;
	void		*escl;
	unsigned int x;
	unsigned int y;
	unsigned int move;
	unsigned int count;
	unsigned int items;
	char		**map;
	unsigned int dir;
	
}				t_vars;

void	maintain_dir(t_vars *vars);
void walk_right(t_vars *vars);
void walk_left(t_vars *vars);
void walk_up(t_vars *vars);
void walk_down(t_vars *vars);
void walk(t_vars *vars, int keycode);
void walkwin(t_vars *vars, int keycode);
int	get_data(t_map *data);
int checkchar(char *map);
int    get_map(t_map *data);
void fetchp(t_map *data);
int checkwalls(t_map *data);
int	checkformat(char *name, char *format);
int	checkelem(char c, char *s);
int	countelem(t_map *data);
int	testmap(unsigned int x, unsigned int y, t_map *data);
int	checking(char *name, t_map *data);
int close_esc(t_vars *vars);
int	getkey(int keycode, t_vars *vars);
void	show_map(t_vars vars);
void vars_init(t_vars *vars, t_map *data);
void put_grass(t_vars vars, int x, int y);
void put_tree(t_vars vars, int x, int y);
void put_play(t_vars vars, int x, int y);
void put_ex(t_vars vars, int x, int y);
int	anim_r0(t_vars *vars);
int	anim_r2(t_vars *vars);
int	anim_l0(t_vars *vars);
int	anim_l2(t_vars *vars);
int	walk_r(t_vars *vars);
int	walk_l(t_vars *vars);
void	walk_u(t_vars *vars);
void	walk_d(t_vars *vars);
void	initframes(t_vars *vars);
void	initframesr(t_vars *vars);
void	initframesl(t_vars *vars);

#endif
