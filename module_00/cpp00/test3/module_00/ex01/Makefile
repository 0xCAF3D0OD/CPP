NAME	= phoneBook
CPP		= g++
CPP_FLG	= -std=c++98 -Wall -Wextra -Werror
CPP_FIL	= phoneBook.cpp\
		  contact.cpp\
		  main.cpp
CPP_DEL	= rm -rf

all: $(NAME)

$(NAME):	$(CPP_FIL)
		$(CPP) $(CPP_FLG) $(CPP_FIL) -o $(NAME)

fclean:
		$(CPP_DEL) $(NAME)

re:		fclean all
