NAME = libftdebugging.a
CC= cc
FLAGES= -Wall -Wextra -Werror
SRC= $(wildcard src/*.c)
INC= $(wildcard includes/*.h)
OBJ= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c ${INC}
	${CC} ${FLAGES} -c $< -o $@

${NAME}: $(OBJ) ${INC}
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re