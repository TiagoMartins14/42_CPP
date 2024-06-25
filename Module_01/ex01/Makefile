# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 16:51:04 by tiaferna          #+#    #+#              #
#    Updated: 2024/06/25 17:35:01 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the target executable
NAME = MoarBrainz!

# Define the source and object files
SRCS = main.cpp zombieHorde.cpp  Zombie.cpp
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
