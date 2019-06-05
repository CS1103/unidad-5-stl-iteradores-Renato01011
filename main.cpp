#include <iostream>
#include "Progression.h"

int main() {

    ArithProgression ap(2, 2, 10);
    std::vector <long> v = get_series(ap);
    for(auto item : v)
        std::cout << item << ',';
    std::cout << std::endl;

    GenProgression gp(4, 2, 32);
    std::vector <long> v1 = get_series(gp);
    for(auto item : v1)
        std::cout << item << ',';
    std::cout << std::endl;

    FibonacciProgression fp(3, 5, 699);
    std::vector <long> v2 = get_series(fp);
    for(auto item : v2)
        std::cout << item << ',';
    std::cout << std::endl;

    return 0;
}