// Complete Guide to C++ Programming Foundations
// Challenge Solution 07_11
// Design a Person Class, by Abdul Mziya

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

class Inventory {
    static int objectCount;
private:
    std::vector<std::string> items;
    int capacity;
public:
    // Constructors
    Inventory() : capacity() { ++objectCount; }
    Inventory(int _capacity): capacity(_capacity) { ++objectCount; }

    // Destructor
    ~Inventory(){ --objectCount; }

    // Getters
    int GetCapacity() const{ return capacity; }

    // Setters
    void SetCapacity(int capacity) { 
        this->capacity = capacity; 
    }

    // Friend function definition
    friend void PrintInventoryItems(const Inventory& __inventory);

    // Operator Functions
    Inventory& operator += (const std::string& item) {
        addItem(item);
        return *this;
    }

    const std::string& operator[](size_t index) {
        return items.at(index);
    }

    // Functions
    void addItem(const std::string& item) {
        if(items.size() <= capacity) {
            items.push_back(item);
        } else {
            std::cout << "Cannot add item, Inventory is full!!" << std::endl;
        }
    }

    void PrintAllItems() {
        std::cout << "All Items: [" ;
        for(size_t i = 0; i < items.size(); i++) {
            std::cout << items[i];
            if (i != items.size() - 1) std::cout << ", ";
        } 
        std::cout << " ]" << std::endl ;
    }

};

int Inventory::objectCount = 0;

void PrintInventoryItems(const Inventory& __inventory){
    std::cout << "All Items: [" ;
    for(size_t i = 0; i < __inventory.items.size(); i++) {
        std::cout << __inventory.items[i];
        if (i != __inventory.items.size() - 1) std::cout << ", ";
    } 
    std::cout << "]" << std::endl ;
};

int main(){
    Inventory myItems(3);
    myItems += "Sword";
    myItems += "Shield";
    myItems += "Potion";
    PrintInventoryItems(myItems);

    myItems.addItem("Axe");
    myItems.PrintAllItems();
    

    std::cout << std::endl << std::endl;
    return 0;
}