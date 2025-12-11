// Complete Guide to C++ Programming Foundations
// Challenge 01_09
// Terminal Interaction, by Abdul Mziya 

#include <iostream>
#include <string>

int main(){
    std::string userName;
    std::cout << "Hi There!" << std::endl;

    std::cout << "What's your name? " << std::flush;
    std::cin >> userName;
    std::cout << "Welcome " << userName << " to C++ programming!" << std::endl;


    std::cout << std::endl << std::endl;
    return 0;
}