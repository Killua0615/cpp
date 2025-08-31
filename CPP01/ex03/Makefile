# Makefile
NAME    = violence
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC     = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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
