#include <iostream>
#include "Account.h"

Account::Account(const std::string accOwner, const int accId, const double initialBalance)
: owner(accOwner), id(accId), balance(0.0) {
    if (initialBalance >= 0.0) balance = initialBalance;
    else std::cout << "Invalid opening balance. Using 0.\n";
}

void Account::deposit(const double amount) {
    if (amount > 0.0) balance += amount;
    else std::cout << "Invalid deposit amount.\n";
}

bool Account::withdraw(const double amount) {
    if (amount <= 0.0) { std::cout << "Invalid withdraw amount.\n"; return false; }
    if (amount > balance) { std::cout << "Insufficient funds.\n"; return false; }
    balance -= amount; return true;
}


std::string Account::getOwner() const { return owner; }
int Account::getId() const { return id; }
double Account::getBalance() const { return balance; }