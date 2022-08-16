/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:16:36 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/14 11:16:44 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_right(t_vars *data)
{
	if (data->buffer[data->index + 1] != '1')
	{
		if (data->buffer[data->index + 1] == 'E')
			is_exit(data);
		else
		{
			is_collect(data, data->buffer[data->index + 1]);
			data->character = data->img[5];
			data->buffer[data->index + 1] = 'P';
			data->buffer[data->index] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->character,
				data->x_pos, data->y_pos);
			ft_printf("Total player move : %d\n", ++data->p_count);
		}
	}
}

void	is_left(t_vars *data)
{
	if (data->buffer[data->index - 1] != '1')
	{
		if (data->buffer[data->index - 1] == 'E')
			is_exit(data);
		else
		{
			is_collect(data, data->buffer[data->index - 1]);
			data->character = data->img[6];
			data->buffer[data->index - 1] = 'P';
			data->buffer[data->index] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->character,
				data->x_pos, data->y_pos);
			ft_printf("Total player move : %d\n", ++data->p_count);
		}
	}
}

void	is_down(t_vars *data)
{
	if (data->buffer[data->index + data->map_width + 1] != '1')
	{
		if (data->buffer[data->index + data->map_width + 1] == 'E')
			is_exit(data);
		else
		{
			is_collect(data, data->buffer[data->index + data->map_width + 1]);
			data->character = data->img[0];
			data->buffer[data->index + data->map_width + 1] = 'P';
			data->buffer[data->index] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->character,
				data->x_pos, data->y_pos);
			ft_printf("Total player move : %d\n", ++data->p_count);
		}
	}
}

void	is_up(t_vars *data)
{
	if (data->buffer[data->index - data->map_width - 1] != '1')
	{
		if (data->buffer[data->index - data->map_width - 1] == 'E')
			is_exit(data);
		else
		{
			is_collect(data, data->buffer[data->index - data->map_width - 1]);
			data->character = data->img[7];
			data->buffer[data->index - data->map_width - 1] = 'P';
			data->buffer[data->index] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->character,
				data->x_pos, data->y_pos);
			ft_printf("Total player move : %d\n", ++data->p_count);
		}
	}
}

int	keyboard(int keycode, t_vars *data)
{
	if (keycode == RIGHT)
		is_right(data);
	if (keycode == LEFT)
		is_left(data);
	if (keycode == UP)
		is_up(data);
	if (keycode == DOWN)
		is_down(data);
	if (keycode == ESC)
		ft_exit(data);
	mlx_clear_window(data->mlx, data->win);
	put_image_background(data);
	put_image(data);
	m_players(data);
	return (keycode);
}
