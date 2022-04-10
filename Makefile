SRC = sources/Banque.cpp \
sources/Arrivee.cpp  \
sources/Caissier.cpp  \
sources/Client.cpp  \
sources/Evenement.cpp  \
sources/FileAttente.cpp  \
sources/FinService.cpp  \
sources/SED.cpp    \
sources/Poisson.cpp \
simu.cpp

OBJ = $(SRC:.cpp=.o)

NAME = simu

all : compile run docs

run : 
	./$(NAME)


compile : $(NAME)

$(NAME) : $(OBJ)                                                       
	g++ -o $(NAME) $(SRC) -W -Wall -Wextra -Werror -g3
	rm -f $(OBJ)

clean :
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf *~
	rm -rf docs

re : fclean all

$(V).SILENT:

DOXYFILE = Doxyfile

docs :
	doxygen $(DOXYFILE)
