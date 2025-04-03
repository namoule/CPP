CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = Unnecessary_violence

SRC = main.cpp HumanA.cpp Weapon.cpp HumanB.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
