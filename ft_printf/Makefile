
# DEFINICIÓN DE VARIABLES
# Hay dos maneras de definirlas:
#.recursivo (use =) - solo busca las variables cuando el comando es usado, no cuando está definido.
#.simplemente expandido (use :=) - como la programación imperativa normal - sólo los definidos hasta ahora se amplían

# flags requeridas
CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

AR	=	ar -rcs

# nombre de la librería
NAME = libftprintf.a

# nombramos los archivos fuente
SRC = ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  ft_putnbr_base.c \
		  ft_putstr_fd.c \
		  ft_putstr_fp.c \
		  ft_printf.c \

# Para cada archivo fuente(.c), si este existe, lo nombramos como archivo objeto(.o) 
OBJ = $(SRC:.c=.o)

# REGLAS

# La primera regla se lleva a efecto en el caso de make se ejecute sin argumentos 
all: $(NAME)

# Creamos la librería
# esta regla tiene como prerrequisito que exista algún fichero objeto
# @ => oculta la salida del comando en la consola
# con ar creamos la librería llamándola NAME añadiéndole los archivos objeto
# finalmente indexamos la librería 
$(NAME): $(OBJ) ft_printf.h
	$(AR) $(NAME) $(OBJ)

# Define un patrón que compila cada archivo .c en un archivo .o
# %.o => encuentra cada archivo objeto
# %.c => cada archivo objeto debe tener como prerrequisito su correspondiente archivo fuente
# $@ => cada archivo objeto (los coge de la regla %.o)
# $< => El nombre del primer prerequisito(%.c => archivos fuente)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina los archivoa objeto(.o)
clean:
	rm -f $(OBJ)
	@echo "OBJ deleted"

# Elimina los archivos objeto y la librería
fclean: clean
	rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

# Evita confundir las siguientes reglas con nombres de archivo(en el caso de existir)
.PHONY: all, clean, fclean, re
