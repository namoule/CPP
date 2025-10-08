#include <iostream>
#include <fstream>
#include <string>

std::string replaceLetter(const std::string &line, char from, char to) {
    std::string result = line;
    for (std::size_t i = 0; i < result.length(); ++i) {
        if (result[i] == from)
            result[i] = to;
    }
    return result;
}

int printInFile(char toChange, char newLetter, std::string output_filename, std::string filename)
{
    std::ifstream input(filename.c_str());
    if (!input)
        return(std::cerr << "cammot open infile.\n" << std::endl, 0);
    std::ofstream output(output_filename.c_str());
    if (!output)
        return(std::cerr << "error while creating output file\n" << std::endl, input.close(), 0);
    std::string line;
    bool firstLine = true;
    while (std::getline(input, line))
    {
        if (!firstLine)
            output << "\n";
        output << replaceLetter(line, toChange, newLetter);
        firstLine = false;
    }
    input.close();
    output.close();
    return(0);
}
int main(int argc, char **argv)
{
    if (argc != 4)
        return(std::cout << "[FILENAME] [CHAR_TO_REPLACE] [CHAR_REPLACEMENT]" <<std::endl, 0);
    std::string filename = argv[1];
    char toChange = argv[2][0];
    char newLetter = argv[3][0];
    std::string output_filename = filename + ".replace";
    printInFile(toChange, newLetter, output_filename, filename);
    return 0;
}
