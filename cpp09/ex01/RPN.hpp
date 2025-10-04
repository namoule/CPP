#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
public:
    RPN(const std::string& expression);
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void PrintValues() const;
    int getResult() const;

    class notokException : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return "Error: Invalid input";
        }
    };

private:
    std::stack<int> _rpn;

    bool ParseValues(const char* value) const;
    void getValues(const std::string& data);
};

#endif // RPN_HPP
