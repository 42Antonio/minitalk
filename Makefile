NAME	= minitalk
SRC = src/server.c src/client.c
FLAGS=-Werror -Wextra -Wall
INCLUDES=ft_printf/libftprintf.a libft/libft.a 

OBJ = $(SRC:.c=.o)		

all: $(NAME)

$(NAME): $(OBJ)

	@make -C ft_printf/ all
	@make -C libft/ all
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	@make -C ft_printf/ clean
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make -C ft_printf/ fclean
	@make -C libft/ fclean

re: fclean all