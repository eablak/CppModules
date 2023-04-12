NAME = referance

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJECTS) 
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJECTS)

.c.o:
	${CC} ${CPPFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re