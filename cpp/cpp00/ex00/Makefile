# Nom du compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Werror -Wextra

# Nom de l'exécutable
TARGET = megaphone

# Fichier source
SRC = megaphone.cpp

# Fichier objet
OBJ = megaphone.o

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compilation du fichier source en fichier objet
$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Suppression complète des fichiers générés (objets et exécutable)
fclean: clean
	rm -f $(TARGET)

# Recompilation complète (nettoie et refait tout)
re: fclean all
