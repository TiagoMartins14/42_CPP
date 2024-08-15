NAME		=	NoYouNeedForm28BNot28C
CXX			=   c++
CXXFLAGS	=   -Wall -Wextra -Werror -Wshadow -pedantic -std=c++98
SRCDIR		=	src
INCDIR		=   includes
SRC			=   main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS		=   $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))
RM			=   rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
