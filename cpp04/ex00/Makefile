CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

TARGET = Animal

SRC = Dog.cpp Cat.cpp main.cpp animal.cpp

OBJ = Dog.o Cat.o main.o animal.o

HEADERS = Dog_class.hpp Cat_class.hpp Animal_class.hpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
