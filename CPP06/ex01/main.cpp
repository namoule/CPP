#include "Serializer.hpp"

int main()
{
    Data d(42);
    uintptr_t raw = Serializer::serialize(&d);
    Data* d2 = Serializer::deserialize(raw);

    std::cout << "Original value: " << d.getValue() << std::endl;
    std::cout << "Deserialized value: " << d2->getValue() << std::endl;

    return 0;
}
