// Complete Guide to C++ Programming Foundations
// Exercise 04_01
// Arrays, by Abdul Mziya

#include <iostream>


// #define LEVEL_COUNT 4

int main(){
    const size_t LEVEL_COUNT = 4;
    int enemies[LEVEL_COUNT];

    enemies[0] = 10;
    enemies[1] = 20;
    enemies[2] = 30;
    enemies[3] = 40;

    std::cout << "The game has " << LEVEL_COUNT << " levels: " << std::endl;
    std::cout << "Level 1 has " << enemies[0] << " enemies " << std::endl;
    std::cout << "Level 2 has " << enemies[1] << " enemies " << std::endl;
    std::cout << "Level 3 has " << enemies[2] << " enemies " << std::endl;  
    std::cout << "Level 4 has " << enemies[3] << " enemies " << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
