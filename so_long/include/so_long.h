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
	void	**f;
	char	**sf;
	void	**lf;
	char	**slf;
	void	**ur;
	char	**sur;
	void	**ul;
	char	**sul;
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
void	anim_r(t_vars *vars);
void	anim_l(t_vars *vars);
void	anim_ul(t_vars *vars);
void	anim_ur(t_vars *vars);
int	walk_r(t_vars *vars);
int	walk_l(t_vars *vars);
void	walk_u(t_vars *vars);
void	walk_d(t_vars *vars);
void	initframes(t_vars *vars);
char	**startframe(t_vars *vars, void **f, char *s, int nb);
void	preppath(char *s, char *nbr, char **text);
char	**textforframes(char *s, int nb);
int	slidein(char **s, char *content, int index);

#endif
