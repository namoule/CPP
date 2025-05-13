CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = this_is_brain

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Zombie.hpp

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
