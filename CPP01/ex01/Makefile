# Makefile
NAME    = zombieHorde
COMPILE = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

SRC     = main.cpp Zombie.cpp zombieHorde.cpp
OBJ_DIR = obj
OBJ     = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re
