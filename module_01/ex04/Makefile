NAME	= Sed
CPP		= g++
CPP_FLG	= -std=c++98 -Wall -Wextra -Werror
CPP_FIL	= main.cpp\

all:	$(NAME)

$(NAME):	$(CPP_FIL)
		$(CPP) $(CPP_FLG) $(CPP_FIL) -o $(NAME)

fclean:
		rm -rf $(NAME)

re:		fclean all

.PHONY: fclean re