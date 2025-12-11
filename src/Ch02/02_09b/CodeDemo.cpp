// Complete Guide to C++ Programming Foundations
// Exercise 02_09
// Structures, by Abdul Mziya 

#include <iostream>
#include <string>

enum class character_role {protagonist, antagonist, sidekick, npc};

struct GameCharacter {
    std::string name;
    int level;
    character_role role;
};

int main(){
    GameCharacter hero;
    hero.name = "Cena";
    hero.level = 5;
    hero.role = character_role::npc;

    std::cout << "Character Name: " << hero.name << std::endl;
    std::cout << "Character Level: " << hero.level << std::endl;
    std::cout << "Character Role: " << (int) hero.role << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
