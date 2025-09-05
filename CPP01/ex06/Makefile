# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nateshim <nateshim@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 22:07:18 by nateshim          #+#    #+#              #
#    Updated: 2025/09/04 22:17:30 by nateshim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = harlFilter
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
SRC     = main.cpp Harl.cpp
OBJDIR  = obj
OBJ     = $(SRC:%.cpp=$(OBJDIR)/%.o)
RM      = rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
run: $(NAME)
	./$(NAME)
clean:
	$(RM) $(OBJDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
