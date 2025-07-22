CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

TARGET = Ex02

SRC = AForm.cpp Bureaucrat.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ = AForm.o Bureaucrat.o main.o PresidentialPardonForm.o RobotomyRequestForm.o ShrubberyCreationForm.o

HEADERS = AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp


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
