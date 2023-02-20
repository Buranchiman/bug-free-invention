/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:41:28 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/20 11:59:50 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	checkformat(char *name, char *format)
{
	size_t	i;
	size_t	size;
	int		j;

	size = ft_strlen(name);
	i = size - 1;
	j = 0;
	while (name[i] != format[0] && i > 0)
		i--;
	if (i == 0)
		return (0);
	while (name[i + j] == format[j] && name[i + j] != '\0')
		j ++;
	if (name[i + j] == '\0')
	{
		if (size - ft_strlen(format) == i)
			return (1);
	}
	ft_printf("Error\nThe chosen map isn't in the .ber format\n");
	return (0);
}

int	checkelem(char c, char *s)
{
	if (ft_strchr(s, c) != NULL)
		return (1);
	return (0);
}

t_map	countelem(t_map data)
{
	int	j;
	int	e;
	int	p;
	int	c;

	j = 0;
	e = 0;
	p = 0;
	c = 0;
	while (data.map[j] != NULL)
	{
		e += checkelem('E', data.map[j]);
		p += checkelem('P', data.map[j]);
		c += checkelem('C', data.map[j]);
		j++;
	}
	if (e != 1 || p != 1 || c < 1)
	{
		data.items = -1;
		return (data);
	}
	data.items = c + e;
	return (data);
}

int	testmap(unsigned int x, unsigned int y, t_map data)
{
	if (data.map[y][x] == 'C' || data.map[y][x] == 'E')
		data.count += 1;
	if (data.count == data.items)
		return (1);
	if (data.map[y][x] == '1')
		return (0);
	if (y > data.nb || x > data.size)
		return (0);
	data.map[y][x] = '1';
	if (x < 0 || y < 0)
		return (0);
	if (testmap(x + 1, y, data) == 1)
		return (1);
	if (testmap(x - 1, y, data) == 1)
		return (1);
	if (testmap(x, y + 1, data) == 1)
		return (1);
	if (testmap(x, y - 1, data) == 1)
		return (1);
	return (0);
}

t_map	checking(char *name, t_map data)
{
	if (checkformat(name, ".ber") == 0)
		return (data);
	data = get_map(get_data(name));
	if (data.map == NULL)
		return (data);
	if (checkwalls(data) == 0)
	{
		ft_printf("Error\nThe map isn't surrounded by walls\n");
		return (data);
	}
	data = countelem(data);
	if (data.items == -1)
	{
		ft_printf("Error\nIncorrect number of Exit/Collectible/Start point\n");
		return (data);
	}
	data.count = 0;
	data = fetchp(data);
	if (testmap(data.x, data.y, data) == 0)
	{
		ft_printf("Error\nCollectible or exit not reachable\n");
		return (data);
	}
	data.error = 1;
	return (data);
}
