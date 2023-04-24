/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:43:29 by wvallee           #+#    #+#             */
/*   Updated: 2023/04/24 14:58:40 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_data(t_map *data)
{
	char	*ret;
	int		i;
	int		fd;

	i = 0;
	fd = open(data->name, O_RDONLY);
	ret = get_next_line(fd);
	data->size = ft_strlen(ret);
	if (ret == NULL)
		return (0);
	free(ret);
	while (ret != NULL)
	{
		i++;
		ret = get_next_line(fd);
		if (ft_strlen(ret) != data->size && ret != NULL)
		{
			free(ret);
			return (0);
		}
		free(ret);
	}
	data->nb = i;
	close(fd);
	return (1);
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

int	get_map(t_map *data)
{
	char			*buffer;
	unsigned int	total;
	int				fd;

	if (get_data(data) == 0)
	{
		ft_printf("Error\n The chosen map isn't a rectangle");
		return (0);
	}
	total = data->size * data->nb;
	buffer = ft_calloc(total + 1, sizeof(char));
	fd = open(data->name, O_RDONLY);
	read(fd, buffer, total);
	data->map = ft_split(buffer, '\n');
	data->buffer = ft_strdup(buffer);
	free(buffer);
	close(fd);
	return (1);
}

int	checkwalls(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (data->map[0][i] == '1' && data->map[0][i] != '\0')
		i++;
	if (data->map[0][i] != '\0')
		return (0);
	i = 0;
	while (data->map[j + 1] != NULL)
	{
		if (data->map[j][0] != '1' || data->map[j][data->size - 2] != '1')
			return (0);
		j++;
	}
	while (data->map[j][i] == '1' && data->map[j][i] != '\0')
		i++;
	if (data->map[j][i] != '\0')
		return (0);
	return (1);
}

int	checkall(char *name, t_map *data)
{
	if (checkformat(name, ".ber") == 0)
		return (0);
	if (get_map(data) == 0)
		return (0);
	if (checkchar(data->buffer) == 0)
	{
		free(data->buffer);
		ft_clear((void **)data->map);
		return (0);
	}
	if (checkwalls(data) == 0)
	{
		ft_clear((void **)data->map);
		free(data->buffer);
		ft_printf("Error\nThe map isn't surrounded by walls\n");
		return (0);
	}
	if (countelem(data) == -1)
	{
		ft_printf("Error\nIncorrect number of Exit/Collectible/Start point\n");
		return (0);
	}
	return (1);
}
