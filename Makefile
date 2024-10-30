NAME=webserv

CPPFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp  ServerSetup/Setup.cpp

CXX = c++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)



fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re