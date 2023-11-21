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
//=================vector======================

    std::vector<int> vectorInput;
    for (int i = 1; i < argc; i++) {
        vectorInput.push_back(atoi(argv[i]));
    }

    std::cout << "Before : ";
    for (size_t i = 0; i < vectorInput.size(); i++){
       std::cout << vectorInput[i] << " ";
    }

    clock_t s = clock();
    p.merg_sort_vector(vectorInput, 0, vectorInput.size() - 1); 
    clock_t d = clock();

    std::cout << "\nAfter : ";
    for (size_t i = 0; i < vectorInput.size(); i++){
       std::cout << vectorInput[i] << " ";
    }
    double time = (static_cast<double>(d - s) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds
    std::cout <<  std::endl << "Time to process a range of  " << vectorInput.size() << " elements with std::vector  : " << time << " us";

//=================list======================
    std::list<int> lst;
    for (int i = 1; i < argc; i++) {
        lst.push_back(atoi(argv[i]));
    }
    clock_t start = clock();   
    p.merg_sort_list(lst); 
    clock_t end = clock();

    double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6; // Convert to microsecond
    std::cout << "\nTime to process a range of " << lst.size() << " elements with std::list  : " << duration << " us" <<std::endl;
    return 0;
}


