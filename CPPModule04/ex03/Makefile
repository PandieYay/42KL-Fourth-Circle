NAME = ./a.out
SRCS = ./main.cpp ./AMateria.cpp ./Ice.cpp ./Cure.cpp ./Character.cpp ./MateriaSource.cpp
INC = ./AMateria.hpp ./Ice.hpp ./Cure.hpp ./ICharacter.hpp ./Character.hpp ./IMateriaSource.hpp ./MateriaSource.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re