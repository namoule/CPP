CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

TARGET = Form

SRC = Bureaucrat.cpp main.cpp Form.cpp
OBJ = Bureaucrat.o main.o Form.o

HEADERS = Bureaucrat.hpp Form.hpp


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
