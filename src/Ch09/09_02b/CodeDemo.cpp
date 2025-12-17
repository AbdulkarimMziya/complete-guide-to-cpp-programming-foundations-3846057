// Complete Guide to C++ Programming Foundations
// Exercise 09_02
// Opening a Text File for Reading, by Abdul Mziya

#include <iostream>
#include <string>
#include <vector>


#include <fstream>

struct Player {
    std::string name;
    int age;
    char position;
};

int main(){
    std::ifstream inFile;
    std::string str;
    int number;
    char letter;

    std::vector<Player> players;

    inFile.open("players.txt");

    if(inFile.is_open()) {
        while(!inFile.eof()) {
            Player p;

            getline(inFile, str);
            p.name = str;

            getline(inFile, str);
            p.age = stoi(str);

            getline(inFile, str);
            p.position = str.at(0);

            players.push_back(p);
        };
    }

    inFile.close();

    for(auto &player : players) {
        std::cout << player.name << ", "
                << player.age << ", "
                << player.position << std::endl;
    }
    
    
    std::cout << std::endl << std::endl;
    return 0;
}
