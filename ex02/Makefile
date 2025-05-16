
CC = c++

CFILES = Account.cpp tests.cpp

CFLAGS = -std=c++98 -Wall -Wextra -Werror

OFILES = $(CFILES:.cpp=.o)

NAME = accounts

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o:

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re