NAME = minitalk
SRCLIENT =   client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

SRCBONUSSERVER = server_bonus.c
OBJBONUSSERVER = $(SRCBONUSSERVER:.c=.o)

SRCBONUSCLIENT = client_bonus.c
OBJBONUSCLIENT = $(SRCBONUSCLIENT:.c=.o)

CFLAGS = -Wall -Wextra -Werror
DFLAGS = ./libft/libft.a ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
		 @make -C ./libft 
		 @make -C ./ft_printf
		 @gcc -o server $(SRCSERVER) $(CFLAGS) $(DFLAGS)
		 @gcc -o client $(SRCLIENT) $(CFLAGS) $(DFLAGS)

bonus: $(OBJBONUSSERVER) $(OBJBONUSCLIENT)
		 @make -C ./libft 
		 @make -C ./ft_printf
		 @gcc -o client_bonus $(SRCBONUSCLIENT) $(CFLAGS) $(DFLAGS)
		 @gcc -o server_bonus $(SRCBONUSSERVER) $(CFLAGS) $(DFLAGS)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT) $(OBJBONUSSERVER) $(OBJBONUSCLIENT)
	rm -f ./libft/*.o 
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client server_bonus client_bonus
	rm -f ./libft/*.o ./libft/*.a 
	rm -f ./ft_printf/*.o ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re bonus