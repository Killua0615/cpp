NAME = phonebook

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ_DIR = objs
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

COMPILE = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
