#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    PmergeMe p;
    if (argc <= 2) {
        std::cout << "Error: No input sequence provided." << std::endl;
        return 1;
    }
    int i = 1;
    while (i < argc) {
        std::string str(argv[i]);
        if (str.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << " Error : Negatve numbers are not allowed" << std::endl;
            return 1;
        }
        i++;
    }
//=================deque======================

    std::deque<int> dequeInput;
    for (int i = 1; i < argc; i++) {
        dequeInput.push_back(atoi(argv[i]));
    }
    std::cout << "Before : ";
    for (size_t i = 0; i < dequeInput.size(); i++){
       std::cout << dequeInput[i] << " ";
    }
    std::cout << std::endl;

    clock_t start = clock();   
    p.merg_sort_deque(dequeInput, 0, dequeInput.size() - 1);      			// Sort the sequence using mergesort
    clock_t end = clock();

    double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds * 486

    std::cout << "\nAfter : ";
    for (size_t i = 0; i < dequeInput.size(); i++){
       std::cout << dequeInput[i] << " ";
    }
    std::cout << "\nTime to process a range of " << dequeInput.size() << " elements with std::deque  : " << duration << " us" <<std::endl;
//=================vector======================

    std::vector<int> vectorInput;
    for (int i = 1; i < argc; i++) {
        vectorInput.push_back(atoi(argv[i]));
    }

    clock_t s = clock();
    p.merg_sort_vector(vectorInput, 0, vectorInput.size() - 1); 
    clock_t d = clock();

    double time = (static_cast<double>(d - s) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds
    std::cout << "Time to process a range of  " << vectorInput.size() << " elements with std::vector  : " << time << " us" <<std::endl;
    return 0;
}