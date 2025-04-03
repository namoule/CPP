#include <iostream>
#include <fstream>
#include <string>

int err(std::string str)
{
    std::cout << str;
    return 1;
}

std::string customReplace(std::string str, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;

    while ((pos = str.find(s1, pos)) != std::string::npos)
    {
        result += str.substr(0, pos);
        result += s2;
        pos += s1.length();
        str = str.substr(pos);
    }

    result += str;
    return result;
}

int main(int argc, char **argv)
{
    std::string s1, s2, filename, replace_file, buff;

    if (argc != 4)
        return err("Send right arguments please! [FILENAME] [S1] [S2]\n");

    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    replace_file = filename + ".replace";
    
    std::ifstream input(filename);
    if (!input)
        return err("Failed to open input file.\n");
    std::ofstream output(replace_file);
    if (!output)
        return err("Failed to create output file.\n");
    while (std::getline(input, buff))
    {
        buff = customReplace(buff, s1, s2);
        output << buff << std::endl;
    }
    input.close();
    output.close();
    return 0;
}
