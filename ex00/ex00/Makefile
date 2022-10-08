NAME		= cpp
CPP			= g++
CPP_FLAG	= -std=c++98 -Wall -Wextra -Werror
CPP_FILE	= ex00.cpp
RM			= rm -rf

all:		$(NAME)

$(NAME):	$(CPP_FILE)
			$(CPP) $(CPP_FLAG) $(CPP_FILE) -o $(NAME)

fclean:
			$(RM) $(NAME)

re: 		fclean all

test:		$(NAME)
			./cpp "shhhhh... I think the students are asleep..."
			./cpp Damnit " ! " "Sorry students, I thought this thing was off."
			./cpp