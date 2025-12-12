// Complete Guide to C++ Programming Foundations
// Exercise 04_06
// The Vector Class, by Abdul Mziya

#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> checkpoints = {"Start", "Forest", "Castle"};

    checkpoints.push_back("Cave");
    checkpoints.push_back("Finish");

    std::cout << "The game has " << checkpoints.size() << " checkpoints." << std::endl;
    std::cout << "The checkpoint at index 2 is " << checkpoints[2] << std::endl;
      
    checkpoints[2] = "Dark Castle";
    std::cout << "The checkpoint at index 2 is now " << checkpoints[2] << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
