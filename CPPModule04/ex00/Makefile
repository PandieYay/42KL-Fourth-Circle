NAME = ./a.out
SRCS = ./main.cpp ./Animal.cpp ./Dog.cpp ./Cat.cpp ./WrongCat.cpp ./WrongAnimal.cpp
INC = ./Animal.hpp ./Dog.hpp ./Cat.hpp ./WrongCat.hpp ./WrongAnimal.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re