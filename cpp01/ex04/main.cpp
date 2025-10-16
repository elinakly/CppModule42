// #include "SedIsForLosers.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string ft_replace(std::ifstream& inputFile, std::string& s1, std::string& s2)
{
	std::stringstream	buffer;
	buffer << inputFile.rdbuf(); //"read buffer" method that returns a pointer to the underlying stream buffer
    std::string content = buffer.str();  //.str gives you the string stored inside the stream (extract all as one sings string)
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) //.find search for substring inside another string.. std::string::npos -- "special "not found"" for .find
    {
        content.erase(pos, s1.length()); //.erase to erase [pos - s1.lenght()] index from string
        content.insert(pos, s2); //.insert to add s2 to index pos
        pos += s2.length();
    }
    return content;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "INVALID INPUT\n";
        return(1);
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open in file\n";
        return(1);
    }
    std::string replaced_content = ft_replace(inputFile, s1, s2);
    inputFile.close();
    std::ofstream outputFile(std::string(argv[1]) + ".replace");
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open out file\n";
        return(1);
    }
    outputFile << replaced_content;
    outputFile.close();
    return(0);
}