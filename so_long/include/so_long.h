/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:13:38 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/20 12:11:25 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ultralibft.h"

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
	int				error;

}				t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*bg;
	void	*mc;
	void 	*l;
	void	*c;
	void	*e;
	void	*esc;
	void	*escl;
	unsigned int x;
	unsigned int y;
	unsigned int move;
	unsigned int count;
	unsigned int items;
	char	**map;
}				t_vars;


void walk_right(t_vars *vars);
void walk_left(t_vars *vars);
void walk_up(t_vars *vars);
void walk_down(t_vars *vars);
void walk(t_vars *vars, int keycode);
t_map	get_data(char *name);
int checkchar(char *map);
t_map    get_map(t_map data);
t_map fetchp(t_map data);
int checkwalls(t_map data);
int	checkformat(char *name, char *format);
int	checkelem(char c, char *s);
t_map	countelem(t_map data);
int	testmap(unsigned int x, unsigned int y, t_map data);
t_map	checking(char *name, t_map data);
void close_esc(t_vars *vars);

#endif
