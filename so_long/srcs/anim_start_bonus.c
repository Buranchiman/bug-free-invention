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

int	initframes(t_vars *vars)
{
	ft_printf("entering init\n");
	if (startframe(vars, &(vars->exitr), "exitr", 7) == 0)
		return (0);
	ft_printf("exitr finished\n");
	if (startframe(vars, &(vars->enterr), "enterr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarr), "exitcarr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->entercarl), "entercarr", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterkeyr), "enterkeyr", 2) == 0)
		return (0);
	if (startframe(vars, &(vars->exitl), "exitl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterl), "enterl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarl), "exitcarl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->exitcarl), "entercarl", 7) == 0)
		return (0);
	if (startframe(vars, &(vars->enterkeyl), "enterkeyl", 2) == 0)
		return (0);
	// if (startframe(vars, &(vars->upleft), "ul", 11) == 0)
	// 	return (0);
	// if (startframe(vars, &(vars->upright), "ur", 11) == 0)
	// 	return (0);
	return (1);
}

int	startframe(t_vars *vars, t_frames *frames, char *s, int nb)
{
	char	**tab;
	int		i;
	int		l;
	int		h;

	i = 0;
	//j = 0;
	frames->f = malloc(sizeof(void *) * (nb + 1));
	if ((frames->f) == NULL)
		return (0);
	ft_printf("filling tab\n");
	tab = textforframes(s, nb);
	while (*tab != NULL)
	{
		ft_printf("%s\n", *tab);
		tab++;
	}
	if (tab == NULL)
		return (0);
	while (i < nb)
	{
		frames->f[i] = mlx_xpm_file_to_image(vars->mlx, tab[i], &l, &h);
		i++;
	}
	ft_clear(tab);
	return (1);
}

void	preppath(char *s, char *nbr, char *text)
{
	int	i;

	i = 0;
	i += slidein(text, "xpm/", i);
	i += slidein(text, s, i);
	i += slidein(text, nbr, i);
	i += slidein(text, ".xpm", i);
}

int	slidein(char *s, char *content, int index)
{
	int	i;

	i = 0;
	while (content[i])
	{
		s[index] = content[i];
		index++;
		i++;
	}
	return (i);
}

char	**textforframes(char *s, int nb)
{
	int		i;
	int		len;
	char	*nbr;
	char	**tab;

	tab = malloc(sizeof(char *) * (nb + 1));
	if (tab == NULL)
		return (NULL);
	i = 1;
	len = ft_strlen(s);
	while (i <= nb)
	{
		nbr = ft_itoa(i);
		tab[i] = ft_calloc((8 + len + ft_strlen(nbr)) + 1, sizeof(char));
		if (tab[i] == NULL)
		{
			ft_clear(tab);
			return (NULL);
		}
		preppath(s, nbr, tab[i]);
		free(nbr);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
