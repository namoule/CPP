CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = Ex01

SRC = main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Fixed.hpp

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
