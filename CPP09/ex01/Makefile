NAME = ex01

FILES = main.cpp\
		RPN.cpp

OBJ = $(FILES:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

CXX = c++

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all