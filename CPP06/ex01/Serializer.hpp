#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"
class Serializer
{
  public:
	Serializer();
	Serializer(Serializer const &other);
	Serializer &operator=(Serializer const &other);
	~Serializer();

	static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
