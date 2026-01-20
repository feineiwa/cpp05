NAME = a.out

CC = c++

INC = ./

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = ${SRC:.cpp=.o}

all : $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all