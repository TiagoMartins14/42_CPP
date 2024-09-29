NAME		=	btc
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -Wshadow -pedantic -std=c++98
SRCDIR		=	sources
INCDIR		=	includes
SRC			=	main.cpp
OBJS		=	$(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))
RM			=	rm -rf


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
