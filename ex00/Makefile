NAME = Megaphone
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC	=	megaphone.cpp
OBJS  =   $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS)  $(OBJS) -o  $(NAME)



%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
