NAME	= Weapon
CPP		= g++
CPP_FLG	= -std=c++98 -Wall -Wextra -Werror -g3
CPP_FIL	= main.cpp\
		  HumanA.cpp\
		  HumanB.cpp\
		  Weapon.cpp
CPP_DEL	= rm -rf

all: $(NAME)

$(NAME):	$(CPP_FIL)
		$(CPP) $(CPP_FLG) $(CPP_FIL) -o $(NAME)

fclean:
		$(CPP_DEL) $(NAME)

re:		fclean all