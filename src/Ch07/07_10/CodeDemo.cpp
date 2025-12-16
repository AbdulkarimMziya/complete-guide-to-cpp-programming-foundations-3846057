// Complete Guide to C++ Programming Foundations
// Challenge 07_10
// Design a Person Class, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

class Person{
private:
    std::string name;
    float energy, happiness, health;

public:
    Person(const std::string& _name, float _energy, float _happiness, float _health): name(_name), energy(_energy), happiness(_happiness), health(_health) {}

    void Eat(float calories) {
        this->energy += (calories * 7.0 / 200.0); 
    }

    void Play(float minutes) {
        happiness += (minutes / 2.0);
        energy -= (minutes / 3.0);
    }

    void Sleep(float hours) {
        this->energy += (hours * 3.75);
        this->health += (hours * 2.5);
    }

    float GetEnergy() {
        return this->energy;
    }

    float GetHappiness() {
        return this->happiness;
    }

    float GetHealth() {
        return this->health;
    }
};

int main(){
    // Example 1
    std::string name = "Alice";
    float energy = 40;
    float happiness = 22;
    float health = 80;

    float calories = 300;
    float playMinutes = 120;
    float sleepHours = 5;

    Person sporty(name, energy, happiness, health);
    sporty.Eat(calories);
    sporty.Play(playMinutes);
    sporty.Sleep(sleepHours);

    std::cout << "Your code returned: { ";
    std::cout << "Energy: " << sporty.GetEnergy() << ", ";
    std::cout << "Happiness: " << sporty.GetHappiness() << ", ";
    std::cout << "Health: " << sporty.GetHealth() << " }" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}