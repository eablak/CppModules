NAME = bureaucrat

SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

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
	rm -f *.exe

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re