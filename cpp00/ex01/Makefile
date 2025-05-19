CXX = g++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

TARGET = PhoneBook

SRC = PhoneBook.cpp Contact.cpp
OBJ = PhoneBook.o Contact.o 
HEADERS = PhoneBook.class.hpp Contact.class.hpp

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
