# Nom du compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

# Nom de l'exécutable
TARGET = PhoneBook

# Fichiers source
SRC = PhoneBook.cpp contact.cpp

# Fichiers objets
OBJ = PhoneBook.o Contact.o  # Ajouter Contact.o ici

# Fichiers d'en-tête
HEADERS = PhoneBook.class.hpp Contact.class.hpp

# Règle par défaut (création de l'exécutable)
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compilation du fichier source en fichier objet
$(OBJ): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRC)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ)

# Suppression complète des fichiers générés
fclean: clean
	rm -f $(TARGET)

# Recompilation complète (nettoie et refait tout)
re: fclean all
