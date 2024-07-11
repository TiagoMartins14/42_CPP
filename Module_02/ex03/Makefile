# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiago <tiago@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 22:55:09 by tiaferna          #+#    #+#              #
#    Updated: 2024/07/11 23:07:04 by tiago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and compiler flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the target executable
NAME = BSP

# Define the source and object files
SRCS = main.cpp Fixed.cpp Point.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target to build the executable
all: $(NAME)

# Rule to link object files into the final executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS)

# Rule to clean the build directory and remove the executable
fclean: clean
	rm -f $(NAME)

# Rule to recompile the project from scratch
re: fclean all

# Phony targets to avoid conflicts with files named 'all', 'clean', 'fclean', or 're'
.PHONY: all clean fclean re