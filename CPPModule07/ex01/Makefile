NAME = ./a.out
SRCS = ./main.cpp
INC = ./iter.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): ${SRCS} ${INC}
	c++ ${FLAGS} -o ${NAME} ${SRCS}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re