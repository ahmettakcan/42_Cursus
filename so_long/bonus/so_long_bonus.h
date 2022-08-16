/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:23:26 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/14 13:26:21 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define UP 13
# define ESC 53
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define PLAYER_U "./img/g_up.xpm"
# define PLAYER_D "./img/g_down.xpm"
# define PLAYER_L "./img/g_left.xpm"
# define PLAYER_R "./img/g_right.xpm"
# define BACKGROUND "./img/background.xpm"
# define COLLECT "./img/collectable2.xpm"
# define WALL "./img/walls.xpm"
# define DOOR "./img/p_door.xpm"

typedef struct s_vars{
	int		index;
	int		indeximg;
	int		indexmap;
	int		img_w;
	int		img_h;
	int		x_pos;
	int		y_pos;
	int		c_total;
	int		p_count;
	void	*mlx;
	void	*win;
	void	**img;
	void	*character;
	char	**map;
	char	*buffer;
	char	*m_player;
	size_t	map_width;
	size_t	map_height;
}				t_vars;

void	is_up(t_vars *data);
void	m_free(t_vars *data);
void	is_down(t_vars *data);
void	is_exit(t_vars *data);
void	is_left(t_vars *data);
void	ft_exit(t_vars *data);
void	is_right(t_vars *data);
void	m_players(t_vars *data);
void	put_image(t_vars *data);
void	check_map(t_vars *data);
void	take_image(t_vars *data);
void	ft_error(t_vars *data, int n);
void	is_collect(t_vars *data, char c);
void	put_image_background(t_vars *data);
void	read_map(t_vars *data, char *argv);
void	wall_control(t_vars *data, char *str);
void	mid_control(t_vars *data, char *str, int *player, int *door);

int		is_x(t_vars *data);
int		folder_control(char *argv);
int		keyboard(int keycode, t_vars *data);
#endif
