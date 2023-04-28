/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:13:38 by wvallee           #+#    #+#             */
/*   Updated: 2023/04/24 15:09:49 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"
# include "mlx.h"

typedef struct s_map
{
	unsigned int	nb;
	unsigned int	size;
	char			*name;
	char			**map;
	char			*buffer;
	int				x;
	int				y;
	int				topx;
	int				topy;
	int				items;
	int				count;
}				t_map;

typedef struct s_frames
{
	void	**f;
	int		nbframes;
}				t_frames;

typedef struct s_vars
{
	t_frames		exitr;
	t_frames		enterr;
	t_frames		exitcarr;
	t_frames		entercarr;
	t_frames		enterkeyr;
	t_frames		exitl;
	t_frames		enterl;
	t_frames		exitcarl;
	t_frames		entercarl;
	t_frames		enterkeyl;
	t_frames		exitupr;
	t_frames		enterupr;
	t_frames		exitcarupr;
	t_frames		entercarupr;
	t_frames		upkeyr;
	t_frames		exitupl;
	t_frames		enterupl;
	t_frames		exitcarupl;
	t_frames		entercarupl;
	t_frames		upkeyl;
	t_frames		exitdownl;
	t_frames		enterdownl;
	t_frames		exitcarldown;
	t_frames		entercarldown;
	t_frames		downlkey;
	t_frames		exitdownr;
	t_frames		enterdownr;
	t_frames		exitcarrdown;
	t_frames		entercarrdown;
	t_frames		downrkey;
	void			*tate;
	void			*mlx;
	void			*win;
	void			*img;
	void			*bg;
	void			*mc;
	void			*l;
	void			*c;
	void			*e;
	void			*esc;
	void			*escl;
	unsigned int	x;
	unsigned int	y;
	unsigned int	topx;
	unsigned int	topy;
	unsigned int	move;
	unsigned int	count;
	unsigned int	items;
	char			**map;
	unsigned int	dir;
	int				contain;	
}				t_vars;

void	maintain_dir(t_vars *vars);
void	walk_right(t_vars *vars);
void	walk_left(t_vars *vars);
void	walk_up(t_vars *vars);
void	walk_down(t_vars *vars);
void	walk(t_vars *vars, int keycode);
void	walkwin(t_vars *vars, int keycode);
int		get_data(t_map *data);
int		checkchar(char *map);
int		get_map(t_map *data);
void	gps(t_map *data, int *x, int *y, char c);
int		checkwalls(t_map *data);
int		checkformat(char *name, char *format);
int		checkelem(char c, char *s);
int		countelem(t_map *data);
int		testmap(unsigned int x, unsigned int y, t_map *data);
int		checking(t_map *data);
int		close_esc(t_vars *vars);
int		getkey(int keycode, t_vars *vars);
void	show_map(t_vars vars);
void	vars_init(t_vars *vars, t_map *data);
void	put_grass(t_vars *vars, int x, int y);
void	put_tree(t_vars *vars, int x, int y);
void	put_play(t_vars *vars, int x, int y);
void	put_ex(t_vars *vars, int x, int y);
void	anim_r(t_vars *vars);
void	anim_l(t_vars *vars);
void	anim_ul(t_vars *vars, int i);
void	anim_ur(t_vars *vars, int i);
void	anim_dl(t_vars *vars, int i);
void	anim_dr(t_vars *vars, int i);
int		walk_r(t_vars *vars);
int		walk_l(t_vars *vars);
void	walk_u(t_vars *vars);
void	walk_d(t_vars *vars);
int		inithorizontal(t_vars *vars);
int		initup(t_vars *vars);
int		initframes(t_vars *vars);
int		startframe(t_vars *vars, t_frames *frames, char *s, int nb);
void	preppath(char *s, char *nbr, char *text);
char	**textforframes(char *s, int nb);
int		slidein(char *s, char *content, int index);
int		close_all(t_vars *vars);
void	close_anim(t_vars *vars, t_frames frames);
int		checkall(char *name, t_map *data);
int		initdown(t_vars *vars);
int		top_g(t_vars *vars);
void	close1(t_vars *vars);
int	getkeyb(int keycode, t_vars *vars);
void	gameover(t_vars *vars, char c);

#endif
