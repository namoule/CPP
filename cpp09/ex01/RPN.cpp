#include "RPN.hpp"
#include <cctype>
#include <iostream>

RPN::RPN(const std::string &expression)
{
	std::cout << "RPN constructor called" << std::endl;
	if (!ParseValues(expression.c_str()))
		throw notokException();
	getValues(expression);
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

RPN::RPN(const RPN &other)
{
	this->_rpn = other._rpn;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_rpn = other._rpn;
	}
	return (*this);
}

void RPN::PrintValues() const
{
	std::stack<float> temp = this->_rpn;
	std::cout << "Stack content (top to bottom):" << std::endl;
	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
}

int RPN::getResult() const
{
	if (_rpn.empty())
		throw std::runtime_error("Error: Stack is empty");
	return (_rpn.top());
}

bool	isop(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool	isnum(char c)
{
	return (std::isdigit(c));
}

int	getnumber(const std::string &s, size_t &pos)
{
	int	sign;
	int	num;

	sign = 1;
	if (s[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	num = 0;
	while (pos < s.size() && isnum(s[pos]))
	{
		num = num * 10 + (s[pos] - '0');
		pos++;
	}
	pos--;
	return (num * sign);
}

bool RPN::ParseValues(const char *value) const
{
	int i = 0;
	while (value[i] != '\0')
	{
		if (value[i] == ' ')
		{
			++i;
			continue ;
		}

		if (isop(value[i]))
		{
			++i;
			continue ;
		}

		if (value[i] == '-' && isnum(value[i + 1]))
		{
			++i;
			while (isnum(value[i]))
				++i;
			continue ;
		}

		if (isnum(value[i]))
		{
			while (isnum(value[i]))
				++i;
			continue ;
		}

		return (false);
	}
	return (true);
}

void RPN::getValues(const std::string &data)
{
	size_t	pos;
	int		num;
	int		b;
	int		a;
	int		res;

	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i] == ' ')
			continue ;
		if (isnum(data[i]) || (data[i] == '-' && i + 1 < data.size()
				&& isnum(data[i + 1])))
		{
			pos = i;
			num = getnumber(data, pos);
			_rpn.push(num);
			i = pos;
		}
		else if (isop(data[i]))
		{
			if (_rpn.size() < 2)
				throw std::runtime_error("Error: Not enough operands");
			b = _rpn.top();
			_rpn.pop();
			a = _rpn.top();
			_rpn.pop();
			res = 0;
			switch (data[i])
			{
			case '+':
				res = a + b;
				break ;
			case '-':
				res = a - b;
				break ;
			case '*':
				res = a * b;
				break ;
			case '/':
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				res = a / b;
				break ;
			case '%':
				if (b == 0)
					throw std::runtime_error("Error: Modulo by zero");
				res = a % b;
				break ;
			}
			_rpn.push(res);
		}
		else
		{
			throw std::runtime_error(std::string("Error: Invalid character '")
				+ data[i] + "'");
		}
	}
	if (_rpn.size() != 1)
	{
		throw std::runtime_error("Error: Expression has too many operands or not enough operators");
	}
}
