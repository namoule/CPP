#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 1;

    char c = 'a';
    if(argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
    else
    {
        while(argv[j])
        {
            while(argv[j][i])
            {
                c = toupper(argv[j][i]);
                std::cout << c;
                i++;
            }
            i = 0;
            j++;
        }
        std::cout << "\n";
    }
    return(0);
}