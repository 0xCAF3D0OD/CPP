NAME	= Zombie
CPP		= g++
CPP_FLG	= -std=c++98 -Wall -Wextra -Werror
CPP_FIL	= 	Zombie.cpp\
			zombieHorde.cpp\
			main.cpp
DEL		= rm -rf

all: $(NAME)

$(NAME):
		$(CPP) $(CPP_FLG) $(CPP_FIL) -o $(NAME)

fclean:
		$(DEL) $(NAME)

re:	fclean all

.PHONY: fclean re