/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:21:18 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/27 18:25:28 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_vars *data, char *argv)
{
	char	*tmp;
	char	*buffer;
	char	*buff;
	int		fd;

	buff = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error(data, 1);
	buffer = ft_calloc(sizeof(char), 1);
	tmp = get_next_line(fd);
	data->map_width = ft_strlen(tmp) - 1;
	data->map_height = 0;
	while (tmp)
	{
		buff = ft_strjoin(buffer, tmp);
		free(buffer);
		free(tmp);
		buffer = buff;
		tmp = get_next_line(fd);
		data->map_height++;
	}
	data->buffer = buffer;
	data->map = ft_split(buffer, '\n');
}

void	mid_control(t_vars *data, char *str, int *player, int *door)
{
	if (*str != '1' || str[data->map_width - 1] != '1')
		ft_error(data, 1);
	str++;
	while (*str)
	{
		if (*str == 'C')
			data->c_total++;
		else if (*str == 'P')
			*player += 1;
		else if (*str == 'E')
			*door += 1;
		else if (*str != '0' && *str != '1')
			ft_error(data, 1);
		str++;
	}
}

void	wall_control(t_vars *data, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			if (str[i] == '\n')
				break ;
			else
				ft_error(data, 1);
		}
		i++;
	}
	if (data->map_width != i)
		ft_error(data, 1);
}

void	check_map(t_vars *data)
{
	size_t	i;
	int		p;
	int		player;
	int		door;

	i = 0;
	p = 0;
	player = 0;
	door = 0;
	while (data->map[i])
	{
		if (i == 0 || i == data->map_height - 1)
			wall_control(data, data->map[i]);
		else
			mid_control(data, data->map[i], &player, &door);
		i++;
	}
	if (player != 1 || door < 1 || data->c_total < 1)
		ft_error(data, 1);
}

void	ft_error(t_vars *data, int n)
{
	int	i;

	if (n == 1)
		ft_printf("Error\n");
	if (data == NULL)
		exit(1);
	i = data->map_height - 1;
	while (i >= 0)
	{
		free(data->map[i]);
		i--;
	}
	free(data->map);
	free(data->buffer);
	free(data);
	exit(1);
}
