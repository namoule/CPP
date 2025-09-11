#include "easyfind.tpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testVector()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout << "[test vector] cherche 3 : ";
    try
    {
        std::vector<int>::iterator r = easyfind(v, 3);
        std::cout << "ici : [" << *r << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "[test vector] cherche 10 : ";
    try
    {
        std::vector<int>::iterator r = easyfind(v, 10);
        std::cout << "ici : [" << *r << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testList()
{
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::cout << "[Test listes] recherche 20 : ";
    try
    {
        std::list<int>::iterator lr = easyfind(l, 20);
        std::cout << "trouve ici : [" << *lr << "]" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "[Test listes] recherche 50 : ";
    try
    {
        std::list<int>::iterator lr = easyfind(l, 50);
        std::cout << "trouve ici [" << *lr << "]" << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testDeque()
{
    std::deque<int> d;
    for(int i = 0; i < 5; ++i)
        d.push_back(i * 10);
    
    std::cout << "[Test deque] Cherche 40 : ";
    try
    {
        std::deque<int>::iterator it = easyfind(d, 40);
        std::cout << "Trouve ici [" << *it << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "[Test deque] Cherche 70 : ";
    try
    {
        std::deque<int>::iterator it = easyfind(d, 70);
        std::cout << "Trouve ici [" << *it  << "]" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    testVector();
    std::cout << "---------------------" << std::endl;
    testList();
    std::cout << "---------------------" << std::endl;
    testDeque();
    std::cout << "---------------------" << std::endl;
    return 0;
}