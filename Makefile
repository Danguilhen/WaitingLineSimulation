# Fichiers sources
SRC = sources/Banque.cpp \
sources/Arrivee.cpp  \
sources/Banque.cpp  \
sources/Caissier.cpp  \
sources/Client.cpp  \
sources/Evenement.cpp  \
sources/FileAttente.cpp  \
sources/FinService.cpp  \
sources/SED.cpp \
sources/Poisson.cpp \
simu.cpp

# Fichiers objets
OBJ = $(SRC:.cpp=.o)
 
# Nom du programme
NAME = simu

all: $(NAME) \
	@rm -f $(OBJ)

$(NAME): $(OBJ)
	@g++ -o $(NAME) $(SRC) -W -Wall -Wextra -Werror -g3 \
    
clean: 
	@rm -rf *.o

fclean: clean \
	@rm -rf $(NAME) \
	@rm -rf *~

re: fclan all
