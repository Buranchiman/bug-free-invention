/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:21:13 by wvallee           #+#    #+#             */
/*   Updated: 2023/03/09 17:11:58 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initframes(t_vars *vars)
{
	vars->frames.sf = startframe(vars->mlx, vars->frames.f, "f", 14);
	vars->frames.slf = startframe(vars->mlx, vars->frames.lf, "lf", 14);
	vars->frames.sul = startframe(vars->mlx, vars->frames.ul, "ul", 11);
	vars->frames.sur = startframe(vars->mlx, vars->frames.ur, "ur", 11);
}

char	**startframe(t_vars *vars, void **f, char *s, int nb)
{
	char	**tab;
	int		i;
	int		l;
	int		h;

	i = 0;
	f = malloc(sizeof(void *) * nb + 1);
	tab = textforframes(s, nb);
	while (i < nb)
	{
		f[i] = mlx_xpm_file_to_image(vars->mlx, tab[i], &l, &h);
		i++;
	}
	return (tab);
}

void	preppath(char *s, char *nbr, char **text)
{
	int	i;

	i = 0;
	ft_printf("%s\n", *text);
	i += slidein(text, "xpm/", i);
	ft_printf("%s\n", *text);
	i += slidein(text, s, i);
	ft_printf("%s\n", *text);
	i += slidein(text, nbr, i);
	ft_printf("%s\n", *text);
	i += slidein(text, ".xpm", i);
	ft_printf("%s\n", *text);
}

int	slidein(char **s, char *content, int index)
{
	int	i;

	i = 0;
	while (content[i])
	{
		ft_printf("index is %d\n", index);
		ft_printf("content is %s\n", content);
		ft_printf("i is %d\n", i );
		s[index] = &content[i];
		index++;
		i++;
	}
	return(i);
}

char	**textforframes(char *s, int nb)
{
	int		i;
	int		len;
	char	*nbr;
	char	**tab;

	tab = malloc(sizeof(char *) * nb + 1);
	i = 0;
	len = ft_strlen(s);
	//ft_putstr_fd("entering\n", 1);
	while (i < nb)
	{
		nbr = ft_itoa(i);
		//ft_putstr_fd(nbr, 1);
		tab[i] = ft_calloc((8 + len + ft_strlen(nbr)) + 1, sizeof(char));
		//ft_putstr_fd("allocated\n", 1);
		preppath(s, nbr, &tab[i]);
		//free(nbr);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
