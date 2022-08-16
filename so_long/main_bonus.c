/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:04:44 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/27 18:24:56 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus/so_long_bonus.h"

void	m_players(t_vars *data)
{
	mlx_string_put(data->mlx, data->win, 16,
		32, 0xffffff, "Total player move : ");
	data->m_player = ft_itoa(data->p_count);
	mlx_string_put(data->mlx, data->win, 156,
		32, 0xffffff, data->m_player);
	free(data->m_player);
}

int	folder_control(char *argv)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 4) == 0)
	{
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*data;

	if (argc == 2)
	{
		if (folder_control(argv[1]) == 0)
			ft_error(NULL, 1);
		data = ft_calloc(sizeof(t_vars), 1);
		data->c_total = 0;
		data->p_count = 0;
		read_map(data, argv[1]);
		check_map(data);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, data->map_width * 64,
				data->map_height * 64, "Ya");
		take_image(data);
		data->character = data->img[0];
		put_image_background(data);
		put_image(data);
		mlx_hook(data->win, 2, 1L << 0, keyboard, data);
		mlx_hook(data->win, 17, 1L << 17, is_x, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
