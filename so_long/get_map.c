/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:43:29 by wvallee           #+#    #+#             */
/*   Updated: 2023/02/17 14:36:43 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	get_data(char *name)
{
	char	*ret;
	int		i;
	int		fd;
	t_map	data;

	data.name = name;
	i = 0;
	fd = open(name, O_RDONLY);
	ret = get_next_line(fd);
	data.size = ft_strlen(ret);
	if (ret == NULL)
		data.size = 0;
	free(ret);
	while (ret != NULL)
	{
		i++;
		ret = get_next_line(fd);
		if (ft_strlen(ret) != data.size && ret != NULL)
			data.size = 0;
		free(ret);
	}
	data.nb = i;
	close(fd);
	return (data);
}

int	checkchar(char *map)
{
	unsigned int	j;

	j = 0;
	while (map[j] != '\0')
	{
		if (map[j] != '0' && map[j] != '1' && map[j] != 'P'
			&& map[j] != 'C' && map[j] != 'E' && map[j] != '\n')
		{
			ft_printf("Error !\nInvalid character found while parsing\n");
			return (0);
		}
		j++;
	}
	return (1);
}

t_map	get_map(t_map data)
{
	char			*buffer;
	unsigned int	total;
	int				fd;

	if (data.size == 0)
	{
		data.map = NULL;
		ft_printf("Error\nThe map chosen isn't a rectangle\n");
		return (data);
	}
	total = data.size * data.nb;
	buffer = calloc(total + 1, sizeof(char));
	fd = open(data.name, O_RDONLY);
	read(fd, buffer, total);
	if (checkchar(buffer) == 0)
	{
		data.map = NULL;
		return (data);
	}
	data.map = ft_split(buffer, '\n');
	data.buffer = ft_strdup(buffer);
	free(buffer);
	close(fd);
	return (data);
}

t_map	fetchp(t_map data)
{
	int	i;
	int	p;

	i = 0;
	while (data.map[i] != NULL)
	{
		p = ft_index(data.map[i], 'P');
		if (p != -1)
		{
			data.y = i;
			data.x = p;
		}
		i++;
	}
	return (data);
}

int	checkwalls(t_map data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (data.map[0][i] == '1' && data.map[0][i] != '\0')
		i++;
	if (data.map[0][i] != '\0')
		return (0);
	i = 0;
	while (data.map[j + 1] != NULL)
	{
		if (data.map[j][0] != '1' || data.map[j][data.size - 2] != '1')
			return (0);
		j++;
	}
	while (data.map[j][i] == '1' && data.map[j][i] != '\0')
		i++;
	if (data.map[j][i] != '\0')
		return (0);
	return (1);
}
