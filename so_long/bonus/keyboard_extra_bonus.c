/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:08:20 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/27 17:00:57 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_vars *data)
{
	if (data->mlx != NULL && data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	m_free(data);
	free(data->buffer);
	free(data);
	exit(0);
}

void	m_free(t_vars *data)
{
	int	i;

	i = data->map_height - 1;
	while (i >= 0)
	{
		free(data->map[i]);
		i--;
	}
	free(data->map);
	if (data->img)
	{
		i = 0;
		while (i < 8)
		{
			mlx_destroy_image(data->mlx, data->img[i]);
			i++;
		}
		free(data->img);
	}
}

int	is_x(t_vars *data)
{
	ft_exit(data);
	return (0);
}

void	is_collect(t_vars *data, char c)
{
	if (c == 'C')
	{
		if (data->c_total > 0)
			data->c_total--;
	}
	else if (c == 'E' && data->c_total == 0)
		ft_exit(data);
}

void	is_exit(t_vars *data)
{
	if (data->c_total != 0)
		return ;
	if (data->c_total == 0)
		ft_printf("Total player move : %d\n", ++data->p_count);
	ft_exit(data);
}
