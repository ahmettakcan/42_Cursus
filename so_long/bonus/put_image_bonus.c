/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:56 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/27 17:01:24 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	for_player(t_vars *data, int i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->character,
		data->x_pos, data->y_pos);
	data->index = i;
}

static void	create_xpm(t_vars *data, char *path, int i)
{
	data->img[i] = mlx_xpm_file_to_image(data->mlx, path,
			&data->x_pos, &data->y_pos);
	if (data->img[i] == 0)
		ft_error(data, 1);
}

void	put_image(t_vars *data)
{
	data->indexmap = -1;
	while (data->buffer[++data->indexmap])
	{
		if (data->buffer[data->indexmap] == '1')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[2], data->x_pos, data->y_pos);
		if (data->buffer[data->indexmap] == '0')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[1], data->x_pos, data->y_pos);
		if (data->buffer[data->indexmap] == 'E')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[3], data->x_pos, data->y_pos);
		if (data->buffer[data->indexmap] == 'C')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img[4], data->x_pos, data->y_pos);
		if (data->buffer[data->indexmap] == 'P')
			for_player(data, data->indexmap);
		data->x_pos += 64;
		if (data->buffer[data->indexmap] == '\n')
		{
			data->x_pos = 0;
			data->y_pos += 64;
		}
	}
	m_players(data);
}

void	take_image(t_vars *data)
{
	data->img = ft_calloc(sizeof(void *), 9);
	create_xpm(data, PLAYER_D, 0);
	create_xpm(data, BACKGROUND, 1);
	create_xpm(data, WALL, 2);
	create_xpm(data, DOOR, 3);
	create_xpm(data, COLLECT, 4);
	create_xpm(data, PLAYER_R, 5);
	create_xpm(data, PLAYER_L, 6);
	create_xpm(data, PLAYER_U, 7);
	data->img[8] = 0;
}

void	put_image_background(t_vars *data)
{
	int	i;

	i = 0;
	data->x_pos = 0;
	data->y_pos = 0;
	while (data->buffer[i])
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[1], data->x_pos, data->y_pos);
		data->x_pos += 64;
		if (data->buffer[i] == '\n')
		{
			data->x_pos = 0;
			data->y_pos += 64;
		}
		i++;
	}
	data->x_pos = 0;
	data->y_pos = 0;
}
