CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = Harl_2_0

SRC = Harl.cpp main.cpp 

OBJ = $(SRC:.cpp=.o)

HEADERS = Harl.hpp


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
