# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nateshim <nateshim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 21:28:06 by nateshim          #+#    #+#              #
#    Updated: 2025/09/09 21:40:22 by nateshim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = a.out
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
SRC     = main.cpp Fixed.cpp
OBJDIR  = obj
OBJ     = $(SRC:%.cpp=$(OBJDIR)/%.o)
RM      = rm -rf

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
