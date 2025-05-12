
CC = c++

CFILES = megaphone.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

OFILES = $(CFILES:.cpp=.o)

NAME = megaphone

all: $(NAME)

NAME: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: 

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
