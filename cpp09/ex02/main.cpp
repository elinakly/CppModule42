#include "PmergeMe.hpp"

static bool run_program(int argc, char *argv[])
{
    {
        PmergeMe<std::vector<int>> vec;
        auto start = std::chrono::high_resolution_clock::now();
        try {
            vec.parse(argc, argv);
            vec.sort_container();
        }catch(const std::exception &e){
            std::cerr << e.what() << "\n";
            return(false);}
        auto end = std::chrono::high_resolution_clock::now();   // stop timing
        std::chrono::duration<double, std::micro> duration = end - start;
        vec.print_result();
        std::cout << "Time to process a range of elements with std::vector<int> "<< std::fixed << std::setprecision(5)
          << duration.count() << " us\n";  
    }

    {
        PmergeMe<std::deque<int>> deq;
        auto start1 = std::chrono::high_resolution_clock::now();
        try {
            deq.parse(argc, argv);
            deq.sort_container();
        }catch(const std::exception &e){
            std::cerr << e.what() << "\n";
            return(false);}
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> duration = end1 - start1;
        std::cout << "Time to process a range of elements with std::deque<int> "<< std::fixed << std::setprecision(5)
          << duration.count() << " us\n";
    }
    return(true);
}

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: wrong usage of input <./program> <number[1]> <number[i]>\n";
        return(1);
    }
    if (!run_program(argc, argv))
        return(0);
    return(0);
}