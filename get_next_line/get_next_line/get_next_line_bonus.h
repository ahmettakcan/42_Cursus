/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:47:22 by aakcan            #+#    #+#             */
/*   Updated: 2022/06/06 20:47:31 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *buf);
char	*get_next_line(int fd);
char	*get_new_line(char *buffer);
char	*first_read(int fd, char *buffer);
int		find_nl_char(char *buffer);
char	*strjoin(char *buffer, char *new_buffer);
char	*get_new_buffer(char *buffer);

#endif
