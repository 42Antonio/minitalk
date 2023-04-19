NAME=server client
SRC=server.c client.c
SRC_BONUS=server_bonus.c client_bonus.c
FLAGS=-Werror -Wextra -Wall
INCLUDES=libft/libft.a

OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)		

all: $(NAME)

server : server.o 

	@make -C libft/ all
	gcc $(FLAGS) -o $@ $< $(INCLUDES)
	
client : client.o

	@make -C libft/ all
	gcc $(FLAGS) -o $@ $< $(INCLUDES)

client_bonus : client_bonus.o

	@make -C libft/ all
	gcc $(FLAGS) -o $@ $< $(INCLUDES)

server_bonus : server_bonus.o 

	@make -C libft/ all
	gcc $(FLAGS) -o $@ $< $(INCLUDES)


%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all