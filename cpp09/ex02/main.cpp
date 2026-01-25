#include "PmergeMe.hpp"

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: wrong usage of input <./program> <number[1]> <number[i]>\n";
        return(1);
    }
    PmergeMe pm;
    auto start = std::chrono::high_resolution_clock::now();
    try {
        pm.parse(argc, argv);
        pm.sort_vec();
        // pm.sort_deq();
    }catch(const std::exception &e){
        std::cerr << e.what() << "\n";
        return(1);}
    auto end = std::chrono::high_resolution_clock::now();   // stop timing
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    pm.print_result();
    std::cout << "Time to process a range of elements with std::vector<int> " << duration << " µs\n";
    return(0);
}