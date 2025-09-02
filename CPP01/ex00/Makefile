# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 21:41:11 by nateshim          #+#    #+#              #
#    Updated: 2025/09/02 21:41:14 by nateshim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = zombies
COMPILE = c++
FLAGS   = -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

SRC     = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
