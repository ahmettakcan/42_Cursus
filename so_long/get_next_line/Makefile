# **************************************************************************  #
#                                                                             #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+          #
#    Created: 2022/01/06 17:04:15 by aakcan            #+#    #+#             #
#    Updated: 2022/01/15 12:17:27 by aakcan           ###   ########.tr       #
#                                                                             #
# **************************************************************************  #

SRCS 			= get_next_line.c get_next_line_utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
