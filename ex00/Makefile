CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17

NAME		= megaphone

SRCS		= megaphone.cpp

OBJ_DIR	= build
OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean f: clean
	rm -f $(NAME)

re: fclean all

v: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  		--error-exitcode=1 ./$(NAME) "asd sdf asd asd asd asd "

.PHONY: all clean fclean re

