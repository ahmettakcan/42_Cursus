SRCS = $(wildcard src/*c)
OBJS = $(SRCS:.c=.o)

BONUS = $(wildcard bonus/*c)
OBJS_BONUS = $(BONUS:.c=.o)

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
MFLAGS	=	./minilibx ./minilibx/libmlx.a ./libft/libft.a \
			./ft_printf/libftprintf.a ./get_next_line/get_next_line.a \
			-framework OpenGL -framework AppKit

NAME	=	so_long
RM	=	rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		make -C ./minilibx
		make -C ./ft_printf
		make -C ./get_next_line
		$(CC) -o $(NAME) main.c ./src/*.c -I $(MFLAGS) $(CFLAGS) 
		
bonus:	$(OBJS_BONUS)
		make -C ./libft
		make -C ./minilibx
		make -C ./ft_printf
		make -C ./get_next_line
		$(CC) -o $(NAME) main_bonus.c ./bonus/*.c -I $(MFLAGS) $(CFLAGS) 
		
fclean: clean
		${RM} ./libft/*.a
		${RM} ./minilibx/*.a
		${RM} ./ft_printf/*.a
		${RM} ./get_next_line/*.a
		${RM} $(NAME)
clean:
		${RM} ./libft/*.o
		${RM} ./minilibx/*.o
		${RM} ./src/*.o
		${RM} ./bonus/*.o
		${RM} ./ft_printf/*.o
		${RM} ./get_next_line/*.o
		
re:		fclean all
		
.PHONY: all fclean clean re bonus
