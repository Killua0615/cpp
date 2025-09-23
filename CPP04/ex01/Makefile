#Makefile
NAME    = zoo_brain
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -pedantic
SRC     = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJDIR  = obj
OBJ     = $(SRC:%.cpp=$(OBJDIR)/%.o)
RM      = rm -rf
HEADER  = Animal.hpp Brain.hpp Cat.hpp Dog.hpp

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
run: $(NAME)
	./$(NAME)
$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean: ; $(RM) $(OBJDIR)
fclean: clean ; $(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
