// Complete Guide to C++ Programming Foundations
// Exercise 05_06
// Traditional For Loops, by Abdul Mziya 

#include <iostream>
#include <vector>

int main(){
    std::vector<int> lapTimes = {92, 85, 88, 90, 87};
    float average = 0.00f;

    for(auto it = lapTimes.begin(); it != lapTimes.end() ; it++ ){
        average += *it;
    }

    average = average / lapTimes.size();

    std::cout << "Lap Time Average is: " << average << std::endl;

    
    std::cout << std::endl << std::endl;
    return 0;
}
