# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 11:39:32 by tiaferna          #+#    #+#              #
#    Updated: 2024/07/02 15:34:12 by tiaferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the compiler and compiler flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Define the target executable
NAME = SedIsForLosers

# Define the source and object files
SRCS = main.cpp error.cpp fileUtils.cpp replaceText.cpp
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
