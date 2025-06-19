CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

TARGET = Animal

SRC = Dog.cpp Cat.cpp main.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = Dog.o Cat.o main.o Animal.o WrongAnimal.o WrongCat.o

HEADERS = DogClass.hpp CatClass.hpp AnimalClass.hpp WrongClassAnimal.hpp WrongClassCat.hpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
