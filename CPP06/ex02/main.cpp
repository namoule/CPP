#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(std::time(0));

    for (int i = 0; i < 5; i++) {
        Base generator;
        Base* obj = generator.generate();

        generator.identify(obj);
        generator.identify(*obj);

        delete obj;
        std::cout << "-------------------------------------" << std::endl;
    }

    return 0;
}

