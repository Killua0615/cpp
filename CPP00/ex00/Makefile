NAME = megaphone

OBJ_DIR = objs/
SRC = megaphone.cpp
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ := $(SRC:%.cpp=%.o)
COMPILE = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	$(COMPILE) $(FLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all